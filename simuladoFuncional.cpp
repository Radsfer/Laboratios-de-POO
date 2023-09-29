#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cliente;
class Pedido
{
private:
    int numPedido;
    string descricao;
    float valor;
    Cliente *cliente;

public:
    Pedido(int numPedido, string &descricao, float valor, Cliente *cliente) : numPedido(numPedido),
                                                                              descricao(descricao), valor(valor), cliente(cliente){};
    int getNumPedido() { return numPedido; }
    string &getDescricao() { return descricao; }
    float getValor() { return valor; }
    Cliente *getCliente() { return cliente; }

    void setNumPedido(int numPedido)
    {
        this->numPedido = numPedido;
    }
};

class Cliente
{

private:
    string nome;
    string telefone;
    string endereco;
    vector<Pedido *> pedidos;

public:
    Cliente(string &nome, string &telefone, string &endereco) : nome(nome), telefone(telefone), endereco(endereco) {}
    vector<Pedido *> &getPedidos() { return pedidos; }
    string &getNome() { return nome; }
    string &getTelefone() { return telefone; }
    string &getEndereco() { return endereco; }

    void cadastrarPedidos(Pedido *pedido)
    {
        pedidos.push_back(pedido);
    }

    void listarPedidos()
    {
        cout << "Peididos de " << nome << ":\n";
        for (const auto &pedido : pedidos)
        {
            cout << "Pedido #" << pedido->getNumPedido() << "\n";
            cout << "Descrição: " << pedido->getDescricao() << "\n";
            cout << "Valor: R$" << pedido->getValor() << "\n";
            cout << "-------------------------------------"
                 << "\n";
        }
    }

    float calcularTotal()
    {
        float total = 0.0;
        for (auto &pedido : pedidos)
        {
            total += pedido->getValor();
        }
        return total;
    }
};

int main()
{
    vector<Cliente> clientes;
    vector<Pedido *> pedidos;

    int aux;
    int numPedido = 1;
    do
    {
        cout << "Menu: " << "\n";
        cout << "1- Cadastrar cliente" << "\n";
        cout << "2- Cadastrar pedido" << "\n";
        cout << "3- Listar pedidos do cliente"<< "\n";
        cout << "4- Mostrar todos os clientes" << "\n";
        cout << "5- Mostrar todos os pedidos"<< "\n";
        cout << "6- Calcular valor total"<< "\n";
        cout << "7- sair"<< "\n";

        cout << "Escolha: ";
        cin >> aux;

        switch (aux)
        {
        case 1:
        {
            string nome, telefone, endereco;

            cout << "Nome: ";
            cin.ignore();
            getline(cin, nome);

            cout << "Telefone: ";
            getline(cin, telefone);

            cout << "Endereço: ";
            getline(cin, endereco);

            
            bool clienteExistente = false;
            for (auto &cliente : clientes)
            {
                if (cliente.getNome() == nome || cliente.getTelefone() == telefone)
                {
                    cout << "Cliente já existe com o mesmo nome ou telefone. Não foi criado um novo cliente." << endl;
                    clienteExistente = true;
                    break;
                }
            }

            if (!clienteExistente)
            {
                clientes.emplace_back(nome, telefone, endereco);
                cout << "Cliente criado com sucesso!" << endl;
            }

            break;
        }
        case 2:
        {
            string descricao, referencia;
            float valor;
            cout << "Descrição: ";
            cin.ignore();
            getline(cin, descricao);
            cout << "Valor: R$";
            cin >> valor;
            cin.ignore();
            cout << "Nome ou telefone do cliente: ";
            getline(cin, referencia);

            Cliente *cliente = nullptr;
            for (auto &c : clientes)
            {
                if (c.getNome() == referencia || c.getTelefone() == referencia)
                {
                    cliente = &c;
                    break;
                }
            }

            if (cliente)
            {
                pedidos.push_back(new Pedido(numPedido++, descricao, valor, cliente));
                cliente->cadastrarPedidos(pedidos.back());
                cout << "Pedido realizado!\n";
            }
            else
            {
                cout << "Cliente não cadastrado, favor realizar cadastro!\n";
            }
            break;
        }
        case 3:
        {
            string ref;
            cout << "Número ou telefone do cliente: ";
            cin.ignore();
            getline(cin, ref);

            bool encontrado = false;
            for (auto &cliente : clientes)
            {
                if (cliente.getNome() == ref || cliente.getTelefone() == ref)
                {
                    cliente.listarPedidos();
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado)
            {
                cout << "Cliente não encontrado." << endl;
            }
            break;
        }
        case 4:
        {
            if (clientes.size() > 0)
            {
                cout << "Lista de Clientes: \n";
                for (auto &cliente : clientes)
                {
                    cout << "Nome: " << cliente.getNome() << "\n";
                    cout << "Telefone: " << cliente.getTelefone() << "\n";
                    cout << "Endereço: " << cliente.getEndereco() << "\n";
                    cout << "Quantidade de pedidos: " << cliente.getPedidos().size() << "\n";
                    cout << "-------------------------------------"
                         << "\n";
                }
            }
            else
            {
                cout << "Não a clientes cadastrados!\n";
            }
            break;
        }
        case 5:
        {
            if (pedidos.size() > 0)
            {
                cout << "Lista de pedidos: \n";
                for (auto &pedido : pedidos)
                {
                    cout << "Pedido #" << pedido->getNumPedido() << "\n";
                    cout << "Descrição: " << pedido->getDescricao() << "\n";
                    cout << "Valor: " << pedido->getValor() << "\n";
                    cout << "Cliente: " << pedido->getCliente()->getNome() << "\n";
                    cout << "-------------------------------------"
                         << "\n";
                }
            }
            else
            {
                cout << "Não há pedidos cadastrados!\n";
            }
            break;
        }
        case 6:
        {
            string ref;
            cout << "Nome ou telefone do cliente: ";
            cin.ignore();
            getline(cin, ref);

            bool encontrado = false;
            for (auto &cliente : clientes)
            {
                if (cliente.getNome() == ref || cliente.getTelefone() == ref)
                {
                    float total = cliente.calcularTotal();
                    cout << "O valor total da compra de " << cliente.getNome() << " é de: R$" << total << endl;
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado)
            {
                cout << "Cliente não encontrado." << endl;
            }
            break;
        }

        case 7:
        {
            cout << "Sair ...\n";
            for (auto &pedido : pedidos)
            {
                delete pedido;
            }

            break;
        }
        default:
            cout << "Opção inválida!\n";
        }

    } while (aux != 7);
    return 0;
}