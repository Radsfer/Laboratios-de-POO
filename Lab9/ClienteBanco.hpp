#ifndef __CLIENTEBANCO_H__
#define __CLIENTEBANCO_H__
#include "Pessoa.hpp"

class ClienteBanco : public Pessoa
{
private:
    std::string numeroConta;
    std::string agencia;

public:
    ClienteBanco();
    ClienteBanco(std::string nome, std::string cpf, std::string numeroConta, std::string agencia) : Pessoa(nome, cpf), numeroConta(numeroConta), agencia(agencia){};
    ~ClienteBanco();
   

    std::string getNumeroConta();
    std::string getAgencia();

    void setNumeroConta(std::string numero);
    void setAgencia(std::string agencia);
};
#endif // __CLIENTEBANCO_H__