#include "FilaBanco.hpp"
#include "ClienteBanco.hpp"
#include <iostream>

int main() {
    FilaBanco filaCliente;

    //Para facilitar os testes Habib
    // ClienteBanco cliente1("Alice", "111.111.111-11", "123456", "789");
    // ClienteBanco cliente2("Bob", "222.222.222-22", "654321", "456");
    // ClienteBanco cliente3("Charlie", "333.333.333-33", "987654", "321");
    // ClienteBanco cliente4("David", "444.444.444-44", "567890", "123");
    // ClienteBanco cliente5("Eva", "555.555.555-55", "345678", "890");
    // filaCliente.enqueue(cliente1);
    // filaCliente.enqueue(cliente2);
    // filaCliente.enqueue(cliente3);
    // filaCliente.enqueue(cliente4);
    // filaCliente.enqueue(cliente5);

    int opcao;

    do {
        std::cout << "----------- Menu -----------" << std::endl;
        std::cout << "Escolha uma opção:" << std::endl;
        std::cout << "1. Adicionar cliente à fila"<< std::endl;
        std::cout << "2. Remover cliente da fila"<< std::endl;
        std::cout << "3. Listar clientes na fila"<< std::endl;
        std::cout << "4. Verificar se a fila está vazia"<< std::endl;
        std::cout << "5. Adicionar cliente com atendimento prioritário"<< std::endl;
        std::cout << "0. Sair"<< std::endl;
        std::cout << "Opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                std::string nome, cpf, numeroConta, agencia;
                std::cout << "Nome: ";
                std::cin >> nome;
                std::cout << "CPF: ";
                std::cin >> cpf;
                std::cout << "Número da conta: ";
                std::cin >> numeroConta;
                std::cout << "Agência: ";
                std::cin >> agencia;

                ClienteBanco cliente(nome, cpf, numeroConta, agencia);
                filaCliente.enqueue(cliente);

                std::cout << "Cliente adicionado à fila.\n";
                break;
            }
            case 2: {
                ClienteBanco clienteRemovido = filaCliente.dequeue();
                std::cout << "Cliente removido: " << clienteRemovido.getNome() << "\n";
                std::cout << "Clientes restantes na fila: " << filaCliente.sizeQueue() << "\n";
                break;
            }
            case 3:
                std::cout << "Clientes na fila:\n";
                filaCliente.printQueue();
                break;
            case 4:
                if (filaCliente.isEmpty()) {
                    std::cout << "A fila está vazia.\n";
                } else {
                    std::cout << "A fila não está vazia.\n";
                }
                break;
            case 5: {
                std::string nome, cpf, numeroConta, agencia;
                std::cout << "Nome: ";
                std::cin >> nome;
                std::cout << "CPF: ";
                std::cin >> cpf;
                std::cout << "Número da conta: ";
                std::cin >> numeroConta;
                std::cout << "Agência: ";
                std::cin >> agencia;

                ClienteBanco cliente(nome, cpf, numeroConta, agencia);
                filaCliente.enqueuePriority(true, cliente);

                std::cout << "Cliente com atendimento prioritário adicionado à fila.\n";
                break;
            }
            case 6:
                std::cout << "Saindo do programa.\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    return 0;
}
