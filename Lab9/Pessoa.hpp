#ifndef __PESSOA_H__
#define __PESSOA_H__
#include<string>
class Pessoa
{
    protected:
        std::string nome;
        std::string cpf;
    public:
        Pessoa(std::string nome,std::string cpf);
        virtual ~Pessoa();
        std::string getNome();
        std::string getCpf();

        void setNome(std::string nome);
        void setCPF(std::string cpf);
};
#endif // __PESSOA_H__