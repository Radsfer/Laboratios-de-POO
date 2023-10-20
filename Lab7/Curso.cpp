#include "Curso.hpp"
#include "Faculdade.hpp"
#include "Disciplina.hpp"
#include "Pessoa.hpp"

string Curso::getNomeCurso()
{
   return nomeCurso;
}
void Curso::cadastrarProfessor(Curso *c)
{
   string nome, endereco, titulacao;
   int num;
   cout << "Digite o nome do professor: ";
   getline(cin, nome);
   cout << "Digite o endereço do professor: ";
   getline(cin, endereco);
   cout << "Digite o título/especialização: ";
   getline(cin, titulacao);

   // Cria um novo professor
   Professor novoProfessor = Professor(nome, endereco, titulacao, c);
   if (professores.size() > 0)
   {
      for (int i = 0; i < professores.size(); i++)
      {
         if (professores[i].getNome() == nome)
         {
            cout << "Professor já existe!\n";
            break;
         }
         else
         {
            professores.push_back(novoProfessor);
         }
      }
   }
   else
   {
      professores.push_back(novoProfessor);
   }

   cout << "Disciplinas disponíveis para associação:" << endl;
   imprimirListaDeDisciplinas();

   cout << "Digite o nome da disciplina para associar: ";
   string nomeDisciplina;
   getline(cin, nomeDisciplina);
   cout << "Digite o numero da turma: ";
   cin >> num;
   cin.ignore();

   while (true)
   {
      Disciplina *disciplina = procurarDisciplina(nomeDisciplina, num);
      Professor *pointProfessor = procurarProfessor(nome);
      if (disciplina != nullptr)
      {
         associarProfessorADisciplina(pointProfessor, disciplina);
         break;
      }
      else
      {
         cout << "Disciplina não encontrada. Tente novamente." << endl;
      }

      cout << "Digite o nome da disciplina para associar: ";
      getline(cin, nomeDisciplina);
      cout << "Digite o numero da turma: ";
      cin >> num;
      cin.ignore();
   }
}
void Curso::cadastrarDisciplina(Curso *c)
{
   string nome;
   int ch, turmaNum = 1;
   cout << "Digite o nome  da disciplina: ";
   getline(cin, nome);
   cout << "Digite a carga horária: ";
   cin >> ch;
   cin.ignore();

   for (int i = 0; i < disciplinas.size(); i++)
   {
      if (disciplinas[i].getNomeDisciplina() == nome)
      {
         turmaNum++;
      }
   }
   Disciplina novaDisciplina = Disciplina(nome, ch, turmaNum, c);
   disciplinas.push_back(novaDisciplina);
   cout << "Disciplina cadastrada!\nAVISO: Não se esqueça de definir o professor!" << endl;
};
void Curso::cadastrarAluno(Curso *c)
{
   string nome, endereco;
   int matricula;

   cout << "Digite o nome do aluno: ";
   getline(cin, nome);

   cout << "Digite o endereço do aluno: ";
   getline(cin, endereco);

   matricula = (alunos.size() > 0) ? alunos.size() + 1 : 1;

   Aluno novoAluno = Aluno(nome, endereco, matricula, c);

   int repetidos = 0;
   for (int i = 0; i < alunos.size(); i++)
   {
      if (alunos[i].getNome() == nome && alunos[i].getEndereco() == endereco)
      {
         repetidos++;
      }
   }

   if (repetidos > 0)
   {
      char confirma;
      cout << "Aviso: Foi encontrado mais " << repetidos << " com o mesmo nome e endereço!\nCerteza que são pessoas diferentes?\ns-Sim\nn-Não";
      cin >> confirma;
      confirma = tolower(confirma);

      if (confirma == 'n')
      {
         cout << "Cadastro cancelado!\n";
         return; 
      }
   }

   
   alunos.push_back(novoAluno);
   cout << "Aluno cadastrado!\n";
   Aluno *pointAluno = procurarAluno(matricula);
 
   matricularAlunoEmDisciplinas(pointAluno);

  
}

void Curso::matricularAlunoEmDisciplinas(Aluno *aluno)
{
   // Limites de CH
   const int CH_MIN = 80;
   const int CH_MAX = 150;

   int chTotal = aluno->calcularCHAluno();

   cout << "Deseja fazer quais disciplinas?" << endl;
   imprimirListaDeDisciplinas();
   cout << "AVISO: precisa de um mínimo de CH:" << CH_MIN << " e um máximo de CH:" << CH_MAX << " das disciplinas somadas!" << endl;

   for (int j = 1; chTotal < CH_MAX; ++j)
   {
      cout << "Digite o nome da disciplina (ou 'sair' para encerrar): ";
      string nomeDisciplina;
      cin >> nomeDisciplina;

      if (nomeDisciplina == "sair")
      {
         if (chTotal < CH_MIN)
         {
            cout << "Carga Horária atual insuficiente." << endl;
         }
         else
         {
            break;
         }
      }
      else
      {
         cout << "Digite o número da Turma: ";
         int num;
         cin >> num;
         cin.ignore();

         Disciplina *copiaDisciplina = disponibilidadeDisciplina(nomeDisciplina, num);

         if (copiaDisciplina != nullptr)
         {
            int CHdisciplina = copiaDisciplina->getCH();

            if (chTotal + CHdisciplina > CH_MAX)
            {
               cout << "Aluno não pode ser associado à disciplina devido a limitações de carga horária." << endl;
            }
            else
            {
               associarAlunoADisciplina(aluno, copiaDisciplina);
               chTotal += CHdisciplina;
            }
         }
         else
         {
            cout << "Nome de disciplina inválido ou disciplina lotada. Tente novamente." << endl;
         }
      }
   }
}

void Curso::imprimirListaDeProfessores()
{
   cout << "### Lista de Professores ###" << endl;
   for (int i = 0; i < professores.size(); i++)
   {
      cout << "Nome: " << professores[i].getNome() << endl;
      cout << "Titulação: " << professores[i].getTitulacao() << endl;
      cout << "Endereço: " << professores[i].getEndereco() << endl;
      cout << "Disponibilidade: " << (professores[i].disponivelParaLecionar() ? "Sim" : "Sobrecarregado") << endl;
      professores[i].listarDisciplinasLecionadas();
      cout << "--------------------------" << endl;
   }
}

void Curso::imprimirListaDeAlunos()
{
   cout << "### Lista de Alunos ###" << endl;
   for (int i = 0; i < alunos.size(); i++)
   {
      cout << "Nome: " << alunos[i].getNome() << endl;
      cout << "Endereço: " << alunos[i].getEndereco() << endl;
      cout << "Matrícula: " << alunos[i].getMatricula() << endl;
      alunos[i].listarMatriculas();
      cout << "--------------------------" << endl;
   }
}

void Curso::imprimirListaDeDisciplinas()
{
   cout << "### Lista de Disciplinas ###" << endl;
   for (int i = 0; i < disciplinas.size(); i++)
   {
      cout << "Disciplina: " << disciplinas[i].getNomeDisciplina() << " (Turma: " << disciplinas[i].getNumTurma() << ")" << endl;
      cout << "Carga Horária: " << disciplinas[i].getCH() << " horas" << endl;
      cout << "Alunos na Turma: " << disciplinas[i].quantidadeAlunos() << endl;
      if (disciplinas[i].temProfessor())
      {
         cout << "Lecionada por: " << disciplinas[i].getNomeDoProfessor() << endl;
      }
      else
      {
         cout << "Lecionada por: Ainda a definir!" << endl;
      }
      cout << "--------------------------" << endl;
   }
}

Disciplina *Curso::disponibilidadeDisciplina(string d, int num)
{
   for (int i = 0; i < disciplinas.size(); i++)
   {
      if (disciplinas[i].getNomeDisciplina() == d && disciplinas[i].getNumTurma() == num && !disciplinas[i].salaCheia())
      {
         return &disciplinas[i];
         break;
      }
   }
   return nullptr;
}
Professor *Curso::disponibilidadeProfessor(string p)
{
   for (int i = 0; i < professores.size(); i++)
   {
      if (professores[i].getNome() == p && professores[i].disponivelParaLecionar())
      {
         return &professores[i];
         break;
      }
   }
   return nullptr;
}

void Curso::associarProfessorADisciplina(Professor *professor, Disciplina *disciplina)
{
   if (professor != nullptr && disciplina != nullptr)
   {
      disciplina->definidoProfessor(professor);
      professor->adicionarDisciplinasLecionar(disciplina);
      cout << "Professor " << professor->getNome() << " associado à disciplina " << disciplina->getNomeDisciplina() << endl;
   }
   else
   {
      cout << "Erro: Professor ou disciplina inválidos!" << endl;
   }
}
Disciplina *Curso::procurarDisciplina(string d, int num)
{
   for (int i = 0; i < disciplinas.size(); i++)
   {
      if (disciplinas[i].getNomeDisciplina() == d && disciplinas[i].getNumTurma() == num)
      {
         return &disciplinas[i];
      }
   }
   return nullptr;
}
Professor *Curso::procurarProfessor(string d)
{
   for (int i = 0; i < professores.size(); i++)
   {
      if (professores[i].getNome() == d)
      {
         return &professores[i];
      }
   }
   return nullptr;
}
void Curso::associarAlunoADisciplina(Aluno *aluno, Disciplina *disciplina)
{
   if (aluno != nullptr && disciplina != nullptr)
   {
      disciplina->associarAluno(aluno);
      aluno->associarDisciplina(disciplina);
      cout << "Aluno " << aluno->getNome() << " associado à disciplina " << disciplina->getNomeDisciplina() << endl;
   }
   else
   {
      cout << "Erro: Aluno ou disciplina inválidos!" << endl;
   }
}
Aluno *Curso::procurarAluno(int matricula)
{
   for (int i = 0; i < alunos.size(); i++)
   {
      if (alunos[i].getMatricula() == matricula)
      {
         return &alunos[i];
      }
   }
   return nullptr;
}
