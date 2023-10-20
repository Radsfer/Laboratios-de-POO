#include "Disciplina.hpp"
#include "Curso.hpp"
#include "Faculdade.hpp"
#include "Pessoa.hpp"

string Disciplina::getNomeDisciplina()
{
   return nomeDisciplina;
};

string Disciplina::getNomeDoProfessor()
{
   if (professorDisciplina == nullptr)
   {
      return "";
   }
   else
   {
      string nomeRecuperado = professorDisciplina->getNome();
      return nomeRecuperado;
   }
};
bool Disciplina::temProfessor()
{
   return (professorDisciplina != nullptr);
}

int Disciplina::getCH()
{
   return ch;
};

int Disciplina::getNumTurma()
{
   return numTurma;
};

void Disciplina::setNomeDisciplina(string nome_da_Disciplina)
{
   this->nomeDisciplina = nome_da_Disciplina;
};
void Disciplina::setCH(int carga)
{
   this->ch = carga;
}

void Disciplina::definidoProfessor(Professor *p)
{
   this->professorDisciplina = p;

};

bool Disciplina::salaCheia() {
        if (alunosDisciplina.size()== 30) {
            return true;
        }else{
         return false;
        }
    
}


int Disciplina::quantidadeAlunos() {
    int count = 0;
    for (int i = 0; i < alunosDisciplina.size(); i++) {
        if (alunosDisciplina[i] != nullptr && !alunosDisciplina[i]->getNome().empty()) {
            count++;
        }
    }
    return count;
}

void Disciplina::associarAluno(Aluno *aluno)
{
   if (aluno != nullptr)
   {
      if (!salaCheia())
      {
         alunosDisciplina.push_back(aluno);
         cout << "Aluno " << aluno->getNome() << " matriculado na disciplina " << nomeDisciplina << endl;

      }
   }
   else
   {
      cout << "Erro: Sala de aula lotada para a disciplina " << nomeDisciplina << endl;
   }
}

