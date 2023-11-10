#ifndef __PROVA_H__
#define __PROVA_H__
#include "Aluno.hpp"

class Prova
{
private:
    std::string disciplina;
    std::string codigoProva;
    float nota;
    Aluno aluno;

public:
    Prova();
    Prova(std::string disciplina, std::string codigoProva, float nota, Aluno aluno) : disciplina(disciplina), codigoProva(codigoProva), nota(nota), aluno(aluno){};
    ~Prova();
    std::string getDisciplina();
    std::string getCodigoProva();
    float getNota();
    Aluno getAluno();

    void setDisciplina(std::string Disciplina);
    void setCodigoProva(std::string CodigoProva);
    void setNota(float Nota);
    void setAluno(Aluno aluno);
};

#endif // __PROVA_H__