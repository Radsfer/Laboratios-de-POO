#include <iostream>
#include <string>
#include <vector>

class PessoaFisica {
public:
    PessoaFisica(std::string nome, std::string endereco, std::string cpf) : nome(nome), endereco(endereco), cpf(cpf) {}

    std::string getNome() const { return nome; }
    std::string getEndereco() const { return endereco; }
    std::string getCPF() const { return cpf; }

private:
    std::string nome;
    std::string endereco;
    std::string cpf;
};

class PessoaJuridica {
public:
    PessoaJuridica(std::string nome, std::string endereco, std::string cnpj) : nome(nome), endereco(endereco), cnpj(cnpj), pessoaFisicaAssociada(nullptr) {}

    std::string getNome() const { return nome; }
    std::string getEndereco() const { return endereco; }
    std::string getCNPJ() const { return cnpj; }

    void associarPessoaFisica(PessoaFisica* pessoaFisica) {
        pessoaFisicaAssociada = pessoaFisica;
    }

    PessoaFisica* getPessoaFisicaAssociada() const {
        return pessoaFisicaAssociada;
    }

private:
    std::string nome;
    std::string endereco;
    std::string cnpj;
    PessoaFisica* pessoaFisicaAssociada;
};

class Associacao {
public:
    Associacao(PessoaFisica* pessoaFisica, PessoaJuridica* pessoaJuridica) : pessoaFisica(pessoaFisica), pessoaJuridica(pessoaJuridica) {}

    PessoaFisica* getPessoaFisica() const { return pessoaFisica; }
    PessoaJuridica* getPessoaJuridica() const { return pessoaJuridica; }

private:
    PessoaFisica* pessoaFisica;
    PessoaJuridica* pessoaJuridica;
};

int main() {
    std::vector<PessoaFisica> pessoasFisicas;
    std::vector<PessoaJuridica> pessoasJuridicas;
    std::vector<Associacao> associacoes;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "a) Cadastrar uma Pessoa Física" << std::endl;
        std::cout << "b) Cadastrar uma Pessoa Jurídica" << std::endl;
        std::cout << "c) Associar uma pessoa física a uma pessoa jurídica" << std::endl;
        std::cout << "d) Imprimir a lista de pessoas físicas cadastradas" << std::endl;
        std::cout << "e) Imprimir a lista de pessoas jurídicas cadastradas" << std::endl;
        std::cout << "f) Imprimir a lista de associações entre pessoas físicas e jurídicas" << std::endl;
        std::cout << "g) Sair" << std::endl;

        char escolha;
        std::cin >> escolha;
        tolower(escolha);

        switch (escolha) {
            case 'a': {
                std::string nome, endereco, cpf;
                std::cout << "Digite o nome da Pessoa Física: ";
                std::cin >> nome;
                std::cout << "Digite o endereço da Pessoa Física: ";
                std::cin >> endereco;
                std::cout << "Digite o CPF da Pessoa Física: ";
                std::cin >> cpf;
                PessoaFisica pessoaFisica(nome, endereco, cpf);
                pessoasFisicas.push_back(pessoaFisica);
                break;
            }
            case 'b': {
                std::string nome, endereco, cnpj;
                std::cout << "Digite o nome da Pessoa Jurídica: ";
                std::cin >> nome;
                std::cout << "Digite o endereço da Pessoa Jurídica: ";
                std::cin >> endereco;
                std::cout << "Digite o CNPJ da Pessoa Jurídica: ";
                std::cin >> cnpj;
                PessoaJuridica pessoaJuridica(nome, endereco, cnpj);
                pessoasJuridicas.push_back(pessoaJuridica);
                break;
            }
            case 'c': {
                int indicePessoaFisica, indicePessoaJuridica;
                std::cout << "Escolha o índice da Pessoa Física: ";
                std::cin >> indicePessoaFisica;
                std::cout << "Escolha o índice da Pessoa Jurídica: ";
                std::cin >> indicePessoaJuridica;

                if (indicePessoaFisica >= 0 && indicePessoaFisica < pessoasFisicas.size() &&
                    indicePessoaJuridica >= 0 && indicePessoaJuridica < pessoasJuridicas.size()) {
                    PessoaFisica* pessoaFisica = &pessoasFisicas[indicePessoaFisica];
                    PessoaJuridica* pessoaJuridica = &pessoasJuridicas[indicePessoaJuridica];
                    
                    // Verifique se a pessoa jurídica já está associada a outra pessoa física
                    if (pessoaJuridica->getPessoaFisicaAssociada() == nullptr) {
                        pessoaJuridica->associarPessoaFisica(pessoaFisica);
                        Associacao associacao(pessoaFisica, pessoaJuridica);
                        associacoes.push_back(associacao);
                        std::cout << "Associação criada com sucesso." << std::endl;
                    } else {
                        std::cout << "Pessoa Jurídica já associada a outra Pessoa Física." << std::endl;
                    }
                } else {
                    std::cout << "Índices inválidos." << std::endl;
                }
                break;
            }
            case 'd': {
                std::cout << "Lista de pessoas físicas cadastradas:" << std::endl;
                for (int i = 0; i < pessoasFisicas.size(); i++) {
                    std::cout << "Índice " << i << ": " << pessoasFisicas[i].getNome() << std::endl;
                }
                break;
            }
            case 'e': {
                std::cout << "Lista de pessoas jurídicas cadastradas:" << std::endl;
                for (int i = 0; i < pessoasJuridicas.size(); i++) {
                    std::cout << "Índice " << i << ": " << pessoasJuridicas[i].getNome() << std::endl;
                }
                break;
            }
            case 'f': {
                std::cout << "Lista de associações entre pessoas físicas e jurídicas:" << std::endl;
                for (int i = 0; i < associacoes.size(); i++) {
                    std::cout << "Índice " << i << ": " << associacoes[i].getPessoaFisica()->getNome() << " -> " << associacoes[i].getPessoaJuridica()->getNome() << std::endl;
                }
                break;
            }
            case 'g': {
                std::cout << "Saindo do programa." << std::endl;
                return 0;
            }
            default: {
                std::cout << "Escolha inválida. Tente novamente." << std::endl;
                break;
            }
        }
    }

    return 0;
}
