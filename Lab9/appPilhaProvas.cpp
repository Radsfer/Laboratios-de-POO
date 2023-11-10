#include "Prova.hpp"
#include "PilhaProvas.hpp"
#include "Aluno.hpp"
#include <iostream>
#include <iomanip>


int main()
{
    PilhaProvas pilhaProvas;

    //Para facilitar os testes Habib
    // Aluno aluno1("Joao", "111.111.111-11", 1, "Engenharia");
    // Aluno aluno2("Maria", "222.222.222-22", 2, "Ciencia da Computacao");
    // Aluno aluno3("Pedro", "333.333.333-33", 3, "Medicina");
    // Aluno aluno4("Ana", "444.444.444-44", 4, "Direito");
    // Aluno aluno5("Carlos", "555.555.555-55", 5, "Arquitetura");   
    // pilhaProvas.push(Prova("Matematica", "MAT001", 7.5, aluno1));
    // pilhaProvas.push(Prova("Programacao", "PROG002", 8.0, aluno2));
    // pilhaProvas.push(Prova("Anatomia", "ANA003", 9.2, aluno3));
    // pilhaProvas.push(Prova("Direito Civil", "DCIV004", 6.8, aluno4));
    // pilhaProvas.push(Prova("Desenho Arquitetonico", "DESEN005", 7.0, aluno5));

    int opcao;

    do
    {
        std::cout << "----------- Menu -----------" << std::endl;
        std::cout << "1. Empilhar Prova" << std::endl;
        std::cout << "2. Desempilhar Prova" << std::endl;
        std::cout << "3. Visualizar Prova no Topo" << std::endl;
        std::cout << "4. Verificar se a Pilha está Vazia" << std::endl;
        std::cout << "5. Imprimir todas as provas" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao)
        {
        case 1: 
        {
            std::string nome, cpf, disciplina, codigoProva;
            float nota;
            int numMatricula;
            std::string curso;

            std::cout << "Digite a disciplina: ";
            std::cin.ignore();
            std::getline(std::cin, disciplina);

            std::cout << "Digite o código da prova: ";
            std::getline(std::cin, codigoProva);

            std::cout << "Digite a nota: ";
            std::cin >> nota;

            std::cout << "Digite o número de matrícula do aluno: ";
            std::cin >> numMatricula;

            std::cout << "Nome: ";
            std::cin.ignore();
            std::getline(std::cin, nome);

            std::cout << "CPF: ";
            std::getline(std::cin, cpf);

            std::cout << "Digite o curso do aluno: ";
            std::getline(std::cin, curso);

            Aluno alunoNovo(nome, cpf, numMatricula, curso);
            pilhaProvas.push(Prova(disciplina, codigoProva, nota, alunoNovo));

            std::cout << "Prova empilhada com sucesso!" << std::endl;

            break;
        }
        case 2: 
        {
            if (!pilhaProvas.isEmpty())
            {
                Prova provaDesempilhada = pilhaProvas.pop();
                std::cout << "Prova desempilhada com sucesso!" << std::endl;
                std::cout << "Disciplina: " << provaDesempilhada.getDisciplina() << std::endl;
                std::cout << "Código da prova: " << provaDesempilhada.getCodigoProva() << std::endl;
                std::cout << "Nota: " << std::fixed << std::setprecision(2) << provaDesempilhada.getNota() << std::endl;
                std::cout << "Aluno: " << provaDesempilhada.getAluno().getNome() << std::endl;
                std::cout << "Curso: " << provaDesempilhada.getAluno().getCurso() << std::endl;
            }
            else
            {
                std::cout << "A pilha está vazia. Não é possível desempilhar." << std::endl;
            }
            break;
        }
        case 3: 
        {
            if (!pilhaProvas.isEmpty())
            {
                Prova provaTopo = pilhaProvas.top();
                std::cout << "Prova no topo da pilha:" << std::endl;
                std::cout << "Disciplina: " << provaTopo.getDisciplina() << std::endl;
                std::cout << "Código da prova: " << provaTopo.getCodigoProva() << std::endl;
                std::cout << "Nota: " << std::fixed << std::setprecision(2) << provaTopo.getNota() << std::endl;
                std::cout << "Aluno: " << provaTopo.getAluno().getNome() << std::endl;
                std::cout << "Curso: " << provaTopo.getAluno().getCurso() << std::endl;
            }
            else
            {
                std::cout << "A pilha está vazia. Não há prova no topo." << std::endl;
            }
            break;
        }
        case 4: 
        {
            if (pilhaProvas.isEmpty())
            {
                std::cout << "A pilha de provas está vazia." << std::endl;
            }
            else
            {
                std::cout << "A pilha de provas não está vazia." << std::endl;
            }
            break;
        }
        case 5:
        {
            if (pilhaProvas.isEmpty())
            {
                std::cout << "A pilha de provas está vazia." << std::endl;
            }
            else
            {
                pilhaProvas.print();
            }
            break;
        }
        case 0: 
            std::cout << "Saindo do programa. Até mais!" << std::endl;
            break;
        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    } while (opcao != 0);

    return 0;
}