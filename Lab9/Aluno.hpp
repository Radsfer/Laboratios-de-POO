#ifndef __ALUNO_H__
#define __ALUNO_H__
#include "Pessoa.hpp"

class Aluno : public Pessoa
{
private:
    int numeroMatricula;
    std::string curso;
public:
    Aluno();
    Aluno(std::string nome,std::string cpf,int numMatricula,std::string curso):Pessoa(nome,cpf),numeroMatricula(numMatricula),curso(curso){}
    ~Aluno();

    int getNumeroMatricula();
    std::string getCurso();

    void setNumeroMatricula(int num);
    void setCurso(std::string curso);
};

#endif // __ALUNO_H__