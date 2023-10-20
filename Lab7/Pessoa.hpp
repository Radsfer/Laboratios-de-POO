#ifndef __PESSOA_H__
#define __PESSOA_H__
#include "Faculdade.hpp"
#include "Disciplina.hpp"
#include "Curso.hpp"
#include <bits/stdc++.h>
using namespace std;
class Curso;
class Disciplina;
class Pessoa
{
private:
    string nome;
    string endereco;

public:
    string getNome();
    string getEndereco();

    
    void setNome(string nome);
    void setEndereco(string endereco);

    Pessoa(string n, string e) : nome(n), endereco(e) {}
};

class Aluno : public Pessoa
{
private:
    int matricula;
    vector<Disciplina *>disciplinasMatriculadas;
    Curso *cursoDiscidente;

public:
    int getMatricula();
    
    
    void matricularDisciplina();
    void listarMatriculas();
    void associarDisciplina(Disciplina*d);
    int calcularCHAluno();

    Aluno(string n, string e, int m, Curso *curso) : matricula(m), cursoDiscidente(curso), Pessoa(n, e) {
        vector<Disciplina *>disciplinasMatriculadas;
    }
};

class Professor : public Pessoa
{
private:
    string titulacao;
    vector<Disciplina *>disciplinasLecionadas;
    Curso *cursoDoscente;

public:
    string getTitulacao();


    void setTitulacao(string titulo);
    void adicionarDisciplinasLecionar(Disciplina*d);
    void listarDisciplinasLecionadas();
    bool disponivelParaLecionar();

    Professor(string n, string e, string t, Curso *curso) : titulacao(t), cursoDoscente(curso), Pessoa(n, e){
        vector<Disciplina *>disciplinasLecionadas;
    };
};

#endif // __PESSOA_H__