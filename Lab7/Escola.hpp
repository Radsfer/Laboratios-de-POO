#ifndef __ESCOLA_H__
#define __ESCOLA_H__

#include<bits/stdc++.h>

using namespace std;

#define toStrig()=to_string;

class Pessoa{
    private:
    string const nome;
    string endereco;
    public:
    string const getNome();
    string getEndereco();

    void setNome(string const nome);
    void setEndereco(string endereco);

    Pessoa();
};
class Aluno: public Pessoa{
    private:
        int const matricula;
    public:
     int getMatricula();

     void setMatricula(int const matricula);
    Aluno();
};
class Professor: public Pessoa{
    private:
        string  titulacao;
        string curso;
    public:
     string getTitulacao();
     string getCurso();

     void setTitulacao(string titulo);
     void setMateria(string materia);

     Professor();
};
class Disciplina{
    private:
        string nomeDisciplina;
        int CH;
        Professor *professor;
    public:
        string getNomeDisciplina();
        int getCH();
        Professor &getProfessor();

        void setNomeDisciplina(string nome_da_Disciplina);
        void setCH(int CH);

        void definidoProfessor();

        Disciplina();


};
class Curso{
    private:
        string nomeCurso;
        vector <Professor> professores;
        vector <Disciplina> disciplina;
        vector <Aluno> alunos;
    public:

    
};


#endif // __ESCOLA_H__