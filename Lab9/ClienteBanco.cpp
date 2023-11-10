#include "ClienteBanco.hpp"

std::string ClienteBanco ::getNumeroConta()
{
    return numeroConta;
}

std::string ClienteBanco ::getAgencia()
{
    return agencia;
}

void ClienteBanco ::setNumeroConta(std::string numero)
{
    this->numeroConta = numero;
}

void ClienteBanco ::setAgencia(std::string agencia)
{
    this->agencia = agencia;
}

ClienteBanco::ClienteBanco() : Pessoa("", ""), numeroConta(""), agencia(""){}
ClienteBanco::~ClienteBanco(){}