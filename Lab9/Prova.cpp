#include "Prova.hpp"

    std::string Prova::getDisciplina()
    {
        return disciplina;
    };
    std::string Prova::getCodigoProva()
    {
        return codigoProva;
    };
    float Prova::getNota()
    {
        return nota;
    };
    Aluno Prova::getAluno()
    {
        return aluno;
    };

    void Prova::setDisciplina(std::string Disciplina)
    {
        this->disciplina=Disciplina;
    };
    void Prova::setCodigoProva(std::string CodigoProva)
    {
        this->codigoProva=CodigoProva;
    };
    void Prova::setNota(float Nota)
    {
        this->nota=Nota;
    };
    void Prova::setAluno(Aluno aluno)
    {
        this->aluno=aluno;
    };

    Prova::Prova():disciplina(""),codigoProva(""),nota(0.0),aluno(Aluno()){};
    Prova::~Prova(){};