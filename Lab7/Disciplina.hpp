#ifndef __DISCIPLINA_H__
#define __DISCIPLINA_H__
#include "Faculdade.hpp"
#include "Pessoa.hpp"
#include "Curso.hpp"
class Curso;
class Professor;
class Aluno;
class Disciplina
{
private:
    string nomeDisciplina;
    int numTurma;
    Professor *professorDisciplina;
    vector<Aluno*>alunosDisciplina;
    int ch;
    Curso *cursoPertencente;

public:
    string getNomeDisciplina();
    int getCH();
    int getNumTurma();
    string getNomeDoProfessor();

    void setNomeDisciplina(string nome_da_Disciplina);
    void setCH(int cargaHoraria);
    bool temProfessor();

    void associarAluno(Aluno *aluno);

    bool salaCheia();
    int quantidadeAlunos();
    void definidoProfessor(Professor*p);

    Disciplina(string d, int num, int numT, Curso *c) : nomeDisciplina(d), ch(num), numTurma(numT), cursoPertencente(c) {
        vector<Aluno*>alunosDisciplina;
        professorDisciplina=nullptr;
    }
};
#endif // __DISCIPLINA_H__