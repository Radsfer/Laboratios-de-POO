#ifndef __FACULDADE_H__
#define __FACULDADE_H__

#include <bits/stdc++.h>
#include "Disciplina.hpp"
#include "Curso.hpp"
#include "Pessoa.hpp"

using namespace std;

class Curso;
class Professor;
class Aluno;
class Disciplina;

class Faculdade
{
private:
    string nomeFaculdade="LAB7";
    vector<Curso> cursos;
public:
    

    string getNomeFaculdade();
    Curso* primeiroCurso();
    void cadastrarCurso();
    Curso* buscarCurso(string curso);
    void listarCursos();

    Faculdade(){};
};
#endif // __FACULDADE_H__