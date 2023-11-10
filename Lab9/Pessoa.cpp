#include "Pessoa.hpp"

void Pessoa::setNome(std::string nome)
{
    this->nome=nome;
}

void Pessoa::setCPF(std::string cpf)
{
    this->cpf=cpf;
}

std::string Pessoa::getNome()
{
    return nome;
}

std::string Pessoa::getCpf()
{
    return cpf;
}
Pessoa::~Pessoa(){}