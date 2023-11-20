#ifndef __PESSSOA_H__
#define __PESSSOA_H__
#include <bits/stdc++.h>
#include "Excecoes.hpp"


using namespace std;

class Pessoa{
    private:
    string nome;
    char sexo;
    string endereco;
    string cpf;
    int telefone;
    int identidade;

    public:
    string getNome();
    string getEndereco();
    string getCpf();
    char getSexo();
    int getTelefone();
    int getIdentidade();
    
    void setNome(string nome);
    void setEndereco(string endereco);
    void setSexo(char sexo);
    void setCpf(string cpf);
    void setTelefone(int telefone);
    void setIdentidade(int identidade);

    void imprimirBase();
    virtual void  imprimir();
    
    Pessoa();
    Pessoa(string n, char s, string e, string c, int tel, int id)
        : nome(n), sexo(s), endereco(e), cpf(c), telefone(tel), identidade(id) {};
};

#endif // __PESSSOA_H__