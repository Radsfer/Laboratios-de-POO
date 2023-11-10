#include "Aluno.hpp"

int Aluno::getNumeroMatricula()
{
    return numeroMatricula;
}
std::string Aluno::getCurso()
{
    return curso;
}

void Aluno::setNumeroMatricula(int num)
{
    this->numeroMatricula = num;
}
void Aluno::setCurso(std::string curso)
{
    this->curso = curso;
}
Aluno::Aluno():Pessoa("",""),numeroMatricula(0),curso(""){};
Aluno::~Aluno(){};