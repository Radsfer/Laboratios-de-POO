#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Pedido; // Declaração antecipada da classe Pedido

class Cliente {
private:
    std::string nome;
    std::string endereco;
    std::string numeroTelefone;
    std::vector<Pedido*> pedidos;

public:
    Cliente(const std::string& nome, const std::string& endereco, const std::string& numeroTelefone)
        : nome(nome), endereco(endereco), numeroTelefone(numeroTelefone) {}

    const std::string& getNome() const { return nome; }
    const std::string& getNumeroTelefone() const { return numeroTelefone; }

    void cadastrarPedido(Pedido* pedido) { pedidos.push_back(pedido); }
    void listarPedidos() const;
    double calcularTotalGasto() const;
};

class Pedido {
private:
    int numeroPedido;
    std::string descricao;
    double valorTotal;
    Cliente* cliente;

public:
    Pedido(int numeroPedido, const std::string& descricao, double valorTotal, Cliente* cliente)
        : numeroPedido(numeroPedido), descricao(descricao), valorTotal(valorTotal), cliente(cliente) {}

    int getNumeroPedido() const { return numeroPedido; }
    const std::string& getDescricao() const { return descricao; }
    double getValorTotal() const { return valorTotal; }
    const Cliente* getCliente() const { return cliente; }
};

void Cliente::listarPedidos() const {
    std::cout << "Pedidos de " << nome << ":\n";
    for (const auto& pedido : pedidos) {
        std::cout << "Número do Pedido: " << pedido->getNumeroPedido() << "\n";
        std::cout << "Descrição: " << pedido->getDescricao() << "\n";
        std::cout << "Valor Total: " << pedido->getValorTotal() << "\n";
        std::cout << "------------------------\n";
    }
}

double Cliente::calcularTotalGasto() const {
    double total = 0.0;
    for (const auto& pedido : pedidos) {
        total += pedido->getValorTotal();
    }
    return total;
}

int main() {
    std::vector<Cliente> clientes;
    std::vector<Pedido> pedidos;

    int escolha;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Cadastrar Cliente\n";
        std::cout << "2. Cadastrar Pedido\n";
        std::cout << "3. Listar Pedidos de um Cliente\n";
        std::cout << "4. Imprimir Lista de Clientes\n";
        std::cout << "5. Imprimir Lista de Pedidos\n";
        std::cout << "6. Calcular Total Gasto por Cliente\n";
        std::cout << "7. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1: {
                std::string nome, endereco, numeroTelefone;
                std::cout << "Nome do Cliente: ";
                std::cin.ignore();
                std::getline(std::cin, nome);
                std::cout << "Endereço do Cliente: ";
                std::getline(std::cin, endereco);
                std::cout << "Número de Telefone do Cliente: ";
                std::getline(std::cin, numeroTelefone);
                clientes.emplace_back(nome, endereco, numeroTelefone);
                break;
            }
            case 2: {
                int numeroPedido;
                std::string descricao, referenciaCliente;
                double valorTotal;
                std::cout << "Número do Pedido: ";
                std::cin >> numeroPedido;
                std::cin.ignore();
                std::cout << "Descrição do Pedido: ";
                std::getline(std::cin, descricao);
                std::cout << "Valor Total do Pedido: ";
                std::cin >> valorTotal;
                std::cin.ignore();
                std::cout << "Nome ou Número de Telefone do Cliente associado: ";
                std::getline(std::cin, referenciaCliente);

                Cliente* cliente = nullptr;
                for (auto& c : clientes) {
                    if (c.getNome() == referenciaCliente || c.getNumeroTelefone() == referenciaCliente) {
                        cliente = &c;
                        break;
                    }
                }

                if (cliente) {
                    pedidos.emplace_back(numeroPedido, descricao, valorTotal, cliente);
                    cliente->cadastrarPedido(&pedidos.back());
                } else {
                    std::cout << "Cliente não encontrado. Cadastre o cliente primeiro.\n";
                }
                break;
            }
            case 3: {
                std::string referenciaCliente;
                std::cout << "Nome ou Número de Telefone do Cliente: ";
                std::cin.ignore();
                std::getline(std::cin, referenciaCliente);

                bool clienteEncontrado = false;
                for (const auto& cliente : clientes) {
                    if (cliente.getNome() == referenciaCliente || cliente.getNumeroTelefone() == referenciaCliente) {
                        cliente.listarPedidos();
                        clienteEncontrado = true;
                        break;
                    }
                }

                if (!clienteEncontrado) {
                    std::cout << "Cliente não encontrado.\n";
                }
                break;
            }
            case 4: {
                std::cout << "Lista de Clientes:\n";
                for (const auto& cliente : clientes) {
                    std::cout << "Nome: " << cliente.getNome() << "\n";
                    std::cout << "Endereço: " << cliente.getNumeroTelefone() << "\n";
                    std::cout << "------------------------\n";
                }
                break;
            }
            case 5: {
                std::cout << "Lista de Pedidos:\n";
                for (const auto& pedido : pedidos) {
                    std::cout << "Número do Pedido: " << pedido.getNumeroPedido() << "\n";
                    std::cout << "Descrição: " << pedido.getDescricao() << "\n";
                    std::cout << "Valor Total: " << pedido.getValorTotal() << "\n";
                    std::cout << "Cliente Associado: " << pedido.getCliente()->getNome() << "\n";
                    std::cout << "------------------------\n";
                }
                break;
            }
            case 6: {
                std::string referenciaCliente;
                std::cout << "Nome ou Número de Telefone do Cliente: ";
                std::cin.ignore();
                std::getline(std::cin, referenciaCliente);

                double totalGasto = 0.0;
                for (const auto& cliente : clientes) {
                    if (cliente.getNome() == referenciaCliente || cliente.getNumeroTelefone() == referenciaCliente) {
                        totalGasto = cliente.calcularTotalGasto();
                        std::cout << "Total Gasto por " << cliente.getNome() << ": " << totalGasto << "\n";
                        break;
                    }
                }

                if (totalGasto == 0.0) {
                    std::cout << "Cliente não encontrado.\n";
                }
                break;
            }
            case 7:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while (escolha != 7);

    return 0;
}
