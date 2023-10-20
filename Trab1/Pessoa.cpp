#include "Pessoa.hpp"

string Pessoa::getNome()
{
    return nome;
};
void Pessoa::setNome(string n)
{
    this->nome = n;
};

string Pessoa::getEndereco()
{
    return endereco;
};

void Pessoa::setEndereco(string e)
{
    this->endereco = e;
}

string Pessoa::getCpf()
{
    return cpf;
};

void Pessoa::setCpf(string c)
{
    this->cpf = c;
};

char Pessoa::getSexo()
{
    return sexo;
};

void Pessoa::setSexo(char s)
{
    this->sexo = s;
};

int Pessoa::getTelefone()
{
    return telefone;
};

void Pessoa::setTelefone(int t)
{
    this->telefone = t;
};

int Pessoa::getIdentidade()
{
    return identidade;
};

void Pessoa::setIdentidade(int id)
{
    this->identidade = id;
};

void Pessoa::imprimirBase()
{
    cout << "Nome: " << nome << endl;
    cout << "Endereço: " << endereco << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Sexo: " << (sexo == 'M' ? "Masculino" : sexo == 'F' ? "Feminino"
                                                 : sexo == 'N'   ? "Não declarado"
                                                                 : "Opção inválida")
         << endl;
    cout << "Telefone: " << telefone << endl;
    cout << "Identidade: " << identidade << endl;
}
void Pessoa::imprimir(){
    imprimirBase();
}