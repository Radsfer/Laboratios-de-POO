#ifndef __PACIENTE_H__
#define __PACIENTE_H__
#include "Pessoa.hpp"

class Paciente : public Pessoa
{
private:
    string relato;
    string medicacao;

public:
    string getRelato();
    string getMedicamentoConsumidoRegular();

    void setRelato(string relato);
    void setMedicamentoConsumidaRegular(string medicacao);

    void imprimir() override;
    Paciente() : Pessoa("", ' ', "", "", 0, 0), relato(""), medicacao("") {};
    Paciente(const Pessoa &pessoa, const string &relato, const string &medicacao)
        : Pessoa(pessoa), relato(relato), medicacao(medicacao) {}
};
#endif // __PACIENTE_H__