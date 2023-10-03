#include "Sistema.hpp"

int main()
{
    vector<SistemaEstelar> sistema;
    vector<Planeta> planeta;
    vector<Satelite> ListaSatelites;
    char aux;
    do
    {

        cout << "Menu:\n";
        cout << "a-Registrar um planeta\n";
        cout << "b-Verificar duplicata em planeta\n";
        cout << "c-Listar planetas\n";
        cout<<"l-Adicionar planetas através de arquivo\n";
        cout << "s-Sair\n";
        cout << "Escolha: ";
        cin >> aux;
        aux = tolower(aux);
        
        switch (aux)
        {
        case 'a':
        {
            string nomeEstrela, nomePlaneta, nomeSatelite,peso;
            int quantidadeDeSatelites;
            cout << "Digite o nome da estrela que o planeta orbita: ";
            cin.ignore();
            getline(cin, nomeEstrela);

            if (sistema.size() > 0)
            {
                for (int i = 0; i < sistema.size(); i++)
                {
                    if (sistema[i].getNomeEstrela() == nomeEstrela)
                    {
                        cout << "Digite o nome do planeta: ";
                        getline(cin, nomePlaneta);
                        cout << "Digite o peso do planeta: ";
                        getline(cin,peso);
                        cout << "Quantos satelites ele possui? ";
                        cin >> quantidadeDeSatelites;
                        cin.ignore();
                        sistema[i].adicionarPlaneta(planeta.emplace_back(nomePlaneta, peso, nomeEstrela));
                        if (quantidadeDeSatelites > 0)
                        {
                            for (int j = 0; j < quantidadeDeSatelites; j++)
                            {
                                cout << "Digite o nome do satélite: ";
                                getline(cin, nomeSatelite);
                                ListaSatelites.emplace_back(nomeSatelite);
                                planeta[planeta.size() - 1].adicionarSatelite(ListaSatelites.back());
                            }
                        }

                    }
                    else
                    {
                    sistema.emplace_back(nomeEstrela);
                    cout << "Digite o nome do planeta: ";
                        getline(cin, nomePlaneta);
                        cout << "Digite o peso do planeta: ";
                        getline(cin,peso);
                        cout << "Quantos satelites ele possui? ";
                        cin >> quantidadeDeSatelites;
                        cin.ignore();
                        sistema[i].adicionarPlaneta(planeta.emplace_back(nomePlaneta, peso, nomeEstrela));
                        if (quantidadeDeSatelites > 0)
                        {
                            for (int j = 0; j < quantidadeDeSatelites; j++)
                            {
                                cout << "Digite o nome do satélite: ";
                                getline(cin, nomeSatelite);
                                ListaSatelites.emplace_back(nomeSatelite);
                                planeta[planeta.size() - 1].adicionarSatelite(ListaSatelites.back());
                            }
                        } 
                    }
                }
            }
            else
            {
                sistema.emplace_back(nomeEstrela);
                cout << "Digite o nome do planeta: ";
                getline(cin, nomePlaneta);
                cout << "Digite o peso do planeta: ";
                getline(cin,peso);
                cout << "Quantos satelites ele possui? ";
                cin >> quantidadeDeSatelites;
                cin.ignore();
                sistema[0].adicionarPlaneta(planeta.emplace_back(nomePlaneta, peso, nomeEstrela));
                if (quantidadeDeSatelites > 0)
                {
                    for (int j = 0; j < quantidadeDeSatelites; j++)
                    {
                        cout << "Digite o nome do satélite: ";
                        getline(cin, nomeSatelite);
                        Satelite novoSatelite(nomeSatelite);
                        ListaSatelites.emplace_back(novoSatelite);
                        planeta[0].adicionarSatelite(novoSatelite);
                    }
                }
            }
            break;
        }
        case 'b':
        {
            string nomePlaneta, nomeEstrela, verificar;
            if (planeta.size() > 0)
            {
                cout << "Digite o nome do planeta que deseja verifica: ";
                cin.ignore();
                getline(cin, nomePlaneta);
                cout << "Digite o nome da estrela que ele orbita: ";
                getline(cin, nomeEstrela);

                for (int i = 0; i < sistema.size(); i++)
                {
                    if (sistema[i].getNomeEstrela() == nomeEstrela)
                    {
                        for (int j = 0; j < planeta.size(); j++)
                        {

                            if (planeta[j].getNomePlaneta() == nomePlaneta && nomePlaneta != verificar)
                            {
                                verificar = nomePlaneta;
                                sistema[i].verificarSePlanetaEIdentico(planeta[j]);
                            }
                        }

                        break;
                    }
                }
            }
            else
            {
                cout << "Não há planetas registrados\n";
            }
            break;
        }
        case 'c':
        {
            if (planeta.size() > 0)
            {
                for (int i = 0; i < planeta.size(); i++)
                {
                    planeta[i].imprimirInformacoes();
                }
            }
            else
            {
                cout << "Nehum planeta registrado ainda!\n";
            }
            break;
        }
        case 'l':
        { // Adicione esta opção para ler dados do arquivo
            ifstream arquivo("dados.txt");
            if (arquivo.is_open())
            {
                string linha;
                while (getline(arquivo, linha))
                {
                    Planeta planetaArquivo = Planeta::parseLinha(linha);
                    // Adicione o objeto Planeta à lista de planetas
                    planeta.push_back(planetaArquivo);
                }
                arquivo.close();
            }
            else
            {
                cerr << "Erro ao abrir o arquivo!" << endl;
            }
            break;
        }
        case 's':
        {
            cout << "Saindo ...\n";
            break;
        }
        default:
            cout << "Opção inválida!\n";
            break;
        }
        }
        while (aux != 's')
            ;
        return 0;
    }