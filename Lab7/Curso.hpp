#ifndef __CURSO_H__
#define __CURSO_H__
#include "Disciplina.hpp"
#include "Faculdade.hpp"
#include "Pessoa.hpp"
#include <bits/stdc++.h>
using namespace std;

class Professor;
class Aluno;
class Disciplina;
class Curso
{
private:
    string nomeCurso;
    vector<Professor> professores;
    vector<Disciplina> disciplinas;
    vector<Aluno> alunos;

public:
    string getNomeCurso();

    void cadastrarProfessor(Curso *c);
    void cadastrarDisciplina(Curso *c);
    void cadastrarAluno(Curso *c);

    void imprimirListaDeProfessores();
    void imprimirListaDeAlunos();
    void imprimirListaDeDisciplinas();

    void associarProfessorADisciplina(Professor *professor, Disciplina *disciplina);
    void associarAlunoADisciplina(Aluno *aluno, Disciplina *disciplina);
    void matricularAlunoEmDisciplinas(Aluno *aluno);

    Disciplina *disponibilidadeDisciplina(string d,int n);
    Disciplina *procurarDisciplina(string d,int n);
    Professor *disponibilidadeProfessor(string p);
    Professor *procurarProfessor(string d);
    Aluno* procurarAluno(int matricula);

    
    Curso(string n) : nomeCurso(n){};
};
#endif // __CURSO_H__