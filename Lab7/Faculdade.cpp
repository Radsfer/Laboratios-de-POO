#include "Faculdade.hpp"
#include "Disciplina.hpp"
#include "Curso.hpp"
#include "Pessoa.hpp"

string Faculdade::getNomeFaculdade()
{
   return nomeFaculdade;
};
void Faculdade::cadastrarCurso()
{
   string nomeCurso;
   cout << "Digite o nome do curso: ";
   getline(cin, nomeCurso);
   bool teste = false;
   for (int i = 0; i < cursos.size(); i++)
   {
      if (cursos[i].getNomeCurso() == nomeCurso)
      {
         cout << "Curso já registrado!\n";
         teste = true;
         break;
      }
   }
   if (!teste)
   {
      Curso novoCurso = Curso(nomeCurso);
      cursos.push_back(novoCurso);
   }
};

Curso *Faculdade::buscarCurso(string curso)
{
   for (int i = 0; i < cursos.size(); i++)
   {
      if (cursos[i].getNomeCurso() == curso)
      {
         return &cursos[i];
      }
   }
   cout << "Curso não encontrado!\n";
   return nullptr;
};

void Faculdade::listarCursos()
{

   cout << "Cursos disponíveis:" << endl;
   if (cursos.size() > 0)
   {
      for (int i = 0; i < cursos.size(); i++)
      {
         cout << i + 1 << "- " << cursos[i].getNomeCurso() << endl;
      }
   }
   else
   {
      cout << "Não a cursos no momento!\n";
   }
};

Curso *Faculdade::primeiroCurso(){
   return &cursos[0];
}
