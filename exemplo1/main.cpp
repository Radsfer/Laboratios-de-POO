#include <iostream>
#include <vector>
#include "Material.hpp"
#include "DVD.hpp"
#include "Livro.hpp"
#include "AudioLivro.hpp"

int main()
{
    std::vector<Material *> materiais;

    while (true)
    {
        std::cout << "MENU:" << std::endl;
        std::cout << "1. Adicionar um Livro" << std::endl;
        std::cout << "2. Adicionar um DVD" << std::endl;
        std::cout << "3. Adicionar um Audiolivro" << std::endl;
        std::cout << "4. Imprimir informações" << std::endl;
        std::cout << "5. Sair" << std::endl;
        int escolha;
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        switch (escolha)
        {
        case 1:
        {
            std::string titulo, autor;
            int num_paginas;
            std::cout << "Informe o título do livro: ";
            std::cin.ignore();
            std::getline(std::cin, titulo);
            std::cout << "Informe o autor do livro: ";
            std::getline(std::cin, autor);
            std::cout << "Informe o número de páginas do livro: ";
            std::cin >> num_paginas;
            materiais.push_back(new Livro(titulo, autor, num_paginas));
            break;
        }
        case 2:
        {
            std::string titulo, autor, duracao;

            std::cout << "Informe o título do DVD: ";
            std::cin.ignore();
            std::getline(std::cin, titulo);
            std::cout << "Informe o autor do DVD: ";
            std::getline(std::cin, autor);
            std::cout << "Informe a duração em minutos do DVD: ";
            std::getline(std::cin, duracao);
            materiais.push_back(new DVD(titulo, autor, duracao));
            break;
        }
        case 3:
        {
            std::string titulo, autor, narrador, duracao;
            int num_paginas;
            std::cout << "Informe o título do Audiolivro: ";
            std::cin.ignore();
            std::getline(std::cin, titulo);
            std::cout << "Informe o autor do Audiolivro: ";
            std::getline(std::cin, autor);
            std::cout << "Informe o número de páginas do Audiolivro: ";
            std::cin >> num_paginas;
            std::cin.ignore();
            std::cout << "Informe a duração em minutos do Audiolivro: ";
            std::getline(std::cin, duracao);
            std::cout << "Informe o narrador do Audiolivro: ";
            std::getline(std::cin, narrador);
            materiais.push_back(new AudioLivro(titulo, autor, num_paginas, duracao, narrador));
            break;
        }
        case 4:
        {
            if (materiais.size() > 0)
            {
                for (int i = 0; i < materiais.size(); i++)
                {
                    std::cout << materiais[i]->descricao();
                    std::cout << std::endl;
                }
            }
            else
            {
                std::cout << "Registre alguns materiais primeiro!" << std::endl;
            }
            break;
        }
        case 5:
        {
             
            for (Material *material : materiais)
            {
                delete material;
            }
            materiais.clear();

            return 0;
        }
        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
            break;
        }
    }

    return 0;
}
