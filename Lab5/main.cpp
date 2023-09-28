#include "FilaDeImpressao.hpp"
#include <iostream>
#include <string>

int main()
{
    FilaDeImpressao filaDeImpressao;
    int escolha;
    std::cout << "\nBemvindo a Copiadora Cpp! \n";
    do
    {

        std::cout << "\nMenu:\n";
        std::cout << "1. Adicionar um documento\n";
        std::cout << "2. Consultar um documento por ID\n";
        std::cout << "3. Listar todos os documentos na fila\n";
        std::cout << "4. Remover um documento por ID\n";
        std::cout << "5. Alterar informações de um documento\n";
        std::cout << "6. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;
        std::cout << "\n";
        switch (escolha)
        {
        case 1:
        {
            int id, numPaginas, prioridade;
            std::string nomeArquivo;

            std::cout << "Digite o ID do documento: ";
            std::cin >> id;
            std::cin.ignore(); // Limpar o buffer do teclado
            std::cout << "Digite o nome do arquivo: ";
            std::getline(std::cin, nomeArquivo);
            std::cout << "Digite a quantidade de páginas: ";
            std::cin >> numPaginas;
            std::cout << "\nAviso! \nA ordem de prioridade é definida por você, use com sabedoria. \n";
            std::cout << "Sendo:\n1-Urgente!\n2-Assim que possível\n3-Sem pressa \n";
            std::cout << "Digite o nível de prioridade (1 a 3): ";
            std::cin >> prioridade;

            Documentos doc(id, nomeArquivo, numPaginas, prioridade);
            filaDeImpressao.adicionarDocumento(doc);
            std::cout << "Documento adicionado à fila de impressão.\n";
            break;
        }
        case 2:
        {
            int id;
            std::cout << "Digite o ID do documento a ser consultado: ";
            std::cin >> id;

            Documentos doc = filaDeImpressao.consultarDocumento(id);
            if (doc.getId_documentos() != -1)
            {
                std::cout << "Informações do documento:\n";
                std::cout << "ID: " << doc.getId_documentos() << "\n";
                std::cout << "Nome do arquivo: " << doc.getNomeDocumento() << "\n";
                std::cout << "Quantidade de páginas: " << doc.getQuantidadePaginas() << "\n";
                std::cout << "Prioridade: " << doc.getPrioridadeNivel() << "\n";
            }
            else
            {
                std::cout << "Documento não encontrado na fila.\n";
            }
            break;
        }
        case 3:
        {
            filaDeImpressao.listarDocumentos();
            break;
        }
        case 4:
        {
            int id;
            std::cout << "Digite o ID do documento a ser removido: ";
            std::cin >> id;

            if (filaDeImpressao.removerDocumento(id))
            {
                std::cout << "Documento removido da fila de impressão.\n";
            }
            else
            {
                std::cout << "Documento não encontrado na fila.\n";
            }
            break;
        }
        case 5:
        {
            int id, numPaginas, prioridade;
            std::string nomeArquivo, novoNome;

            std::cout << "Digite o ID do documento a ser alterado: ";
            std::cin >> id;

            Documentos doc = filaDeImpressao.consultarDocumento(id);
            if (doc.getId_documentos() != -1)
            {
                std::cout << "Digite o novo nome do arquivo: ";
                std::cin.ignore();
                std::getline(std::cin, novoNome);
                std::cout << "Digite a nova quantidade de páginas: ";
                std::cin >> numPaginas;
                std::cout << "Digite a nova prioridade (1 a 3): ";
                std::cin >> prioridade;

                
                Documentos novoDocumento(id, novoNome, numPaginas, prioridade);
                filaDeImpressao.atualizarDocumento(novoDocumento);

                std::cout << "Informações do documento alteradas com sucesso.\n";
            }
            else
            {
                std::cout << "Documento não encontrado na fila.\n";
            }
            break;
        }

        case 6:
        {
            std::cout << "Encerrando o programa.\n";
            break;
        }
        default:
        {
            std::cout << "Opção inválida. Tente novamente.\n";
            break;
        }
        }
    } while (escolha != 6);

    return 0;
}
