#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include "Curso.hpp"
#include "Faculdade.hpp"

string Pessoa::getNome()
{
   return nome;
};
string Pessoa::getEndereco()
{
   return endereco;
};

void Pessoa::setNome(string nome)
{
   this->nome = nome;
};
void Pessoa::setEndereco(string endereco)
{
   this->endereco = endereco;
};

int Aluno::getMatricula()
{
   return matricula;
};

void Aluno::associarDisciplina(Disciplina *d)
{

   disciplinasMatriculadas.push_back(d);
}
void Aluno::listarMatriculas()
{
   if (disciplinasMatriculadas.size() > 0)
   {
      cout << "Está matriculado nas disciplinas: " << disciplinasMatriculadas[0]->getNomeDisciplina();
      for (int i = 1; i < disciplinasMatriculadas.size(); i++)
      {
         cout << ", ";
         cout << disciplinasMatriculadas[i]->getNomeDisciplina();
      }
      cout << endl;
   }
   else
   {
      cout << "Ainda não está matriculado em nenhuma disciplina!\n";
   }
}

string Professor::getTitulacao()
{
   return titulacao;
};

void Professor::setTitulacao(string titulo)
{
   this->titulacao = titulo;
};
void Professor::adicionarDisciplinasLecionar(Disciplina *d)
{
   if (disciplinasLecionadas.size() < 10)
   {
      disciplinasLecionadas.push_back(d);
   }
   else
   {
      cout << "Atingiu o limite de 10 aulas!" << endl;
   }
};

bool Professor::disponivelParaLecionar()
{
   if (disciplinasLecionadas.size() == 10)
   {
      return false;
   }
   else
   {
      return true;
   }
};

void Professor::listarDisciplinasLecionadas()
{
   if (disciplinasLecionadas.size() == 1)
   {
      cout << "leciona a disciplina: " << disciplinasLecionadas[0]->getNomeDisciplina();
      cout << endl;
   }
   else if (disciplinasLecionadas.size() >= 2)
   {
      cout << "leciona as disciplinas: " << disciplinasLecionadas[0]->getNomeDisciplina();
      for (int i = 1; i < disciplinasLecionadas.size(); i++)
      {

         cout << ", ";
         cout << disciplinasLecionadas[i]->getNomeDisciplina();
      }
      cout << endl;
   }
   else
   {
      cout << "Não tem disciplinas para lecionar!\n";
   }
};

int Aluno::calcularCHAluno()
{
   int chTotal = 0;

   for (Disciplina* disciplina : disciplinasMatriculadas)
   {
      chTotal += disciplina->getCH();
   }

   return chTotal;
}

