#ifndef __MEDICO_H__
#define __MEDICO_H__
#include "Pessoa.hpp"

class Medico : public Pessoa
{
private:
    int crm;
    string especialidade;

public:
    void imprimir() override;

    int getCrm();
    void setCrm(int crm);

    string getEspecialidade();
    void setEspecialidade(string especialidade);
    
    Medico() : Pessoa("", ' ', "", "", 0, 0), crm(0), especialidade("") {};
    Medico(const Pessoa &pessoa, int crm, const string &especialidade)
        : Pessoa(pessoa), crm(crm), especialidade(especialidade) {}
};

#endif // __MEDICO_H__