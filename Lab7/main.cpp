#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include "Curso.hpp"
#include "Faculdade.hpp"

int main()
{
    Faculdade faculdade = Faculdade();
    cout << "Bem vindo a Faculdade " << faculdade.getNomeFaculdade() << endl;
    cout << "Para começar vamos registrar o primeiro curso!\n";
    bool start = true;
    char aux = 'a';

    do
    {
        if (!start)
        {
            cout << "Menu:\n";
            cout << "a- Cadastrar um novo curso\n";
            cout << "b- Cadastrar uma nova Disciplina\n";
            cout << "c- Cadastrar um novo Professor\n";
            cout << "d- Cadastrar um novo aluno\n";
            cout << "e- Definir professor para disciplina\n";
            cout << "f- Matricular aluno em disciplina \n";
            cout << "t- imprime todas as infos\n";
            cout << "s- Sair\n";
            cout << "Escolha: ";
            cin >> aux;
            aux = tolower(aux);
        }

        switch (aux)
        {
        case 'a':
        {
            faculdade.cadastrarCurso();
            cout << "Um curso novo precisa de pelo menos 3 disciplinas!\n";
            aux = 'b';
            start = true;
            break;
        }
        case 'b':
        {
            int j = 0;
            while (true)
            {
                j++;
                if (start)
                {
                    Curso *inicialCurso = faculdade.primeiroCurso();
                    inicialCurso->cadastrarDisciplina(inicialCurso);
                }
                else
                {
                    string cursoDesejado;
                    cout << "Digite o nome do curso para cadastrar nova Disciplina: ";
                    cin.ignore();
                    getline(cin, cursoDesejado);
                    Curso *pointCurso = faculdade.buscarCurso(cursoDesejado);
                    if (pointCurso != nullptr)
                    {
                        pointCurso->cadastrarDisciplina(pointCurso);
                    }
                    else
                    {
                        cout << "Curso Não encontrado" << endl;
                    }
                    break;
                }
                if (j >= 3)
                {
                    start = false;
                    break;
                }
            }
            break;
        }
        case 'c':
        {
            string cursoDesejado;
            cout << "Digite o nome do curso para cadastrar do curso: ";
            cin.ignore();
            getline(cin, cursoDesejado);
            Curso *pointCurso = faculdade.buscarCurso(cursoDesejado);
            if (pointCurso != nullptr)
            {
                pointCurso->cadastrarProfessor(pointCurso);
            }
            else
            {
                cout << "Curso Não encontrado" << endl;
            }

            break;
        }
        case 'd':
        {
            string cursoDesejado;
            cout << "Digite o nome do curso: ";
            cin.ignore();
            getline(cin, cursoDesejado);
            Curso *pointCurso = faculdade.buscarCurso(cursoDesejado);
            pointCurso->cadastrarAluno(pointCurso);

            break;
        }
        case 'e':
        {
            string cursoDesejado, nomeD, nomeP;
            int num;
            cout << "Digite o nome do curso: ";
            cin.ignore();
            getline(cin, cursoDesejado);
            Curso *pointCurso = faculdade.buscarCurso(cursoDesejado);

            if (pointCurso != nullptr)
            {
                pointCurso->imprimirListaDeDisciplinas();

                cout << "Digite o nome da Disciplina: ";
                getline(cin, nomeD);
                cout << "Digite o numero da turma: ";
                cin >> num;
                cin.ignore();

                pointCurso->imprimirListaDeProfessores();

                cout << "Digite o nome do Professor: ";
                getline(cin, nomeP);

                Disciplina *pointD = pointCurso->procurarDisciplina(nomeD, num);
                Professor *pointP = pointCurso->disponibilidadeProfessor(nomeP);
                pointCurso->associarProfessorADisciplina(pointP, pointD);
            }
            else
            {
                cout << "Curso Não encontrado" << endl;
            }
            break;
        }
        case 'f':
        {
            string cursoDesejado, nomeD;
            int numD, numA;
            cout << "Digite o nome do curso: ";
            cin.ignore();
            getline(cin, cursoDesejado);
            Curso *pointCurso = faculdade.buscarCurso(cursoDesejado);
            if (pointCurso != nullptr)
            {
                pointCurso->imprimirListaDeAlunos();
                cout << "Digite o numero da matricula: ";
                cin >> numA;
                cin.ignore();
                Aluno *pointA = pointCurso->procurarAluno(numA);
                pointCurso->matricularAlunoEmDisciplinas(pointA);
            }
            else
            {
                cout << "Curso Não encontrado" << endl;
            }

            break;
        }
        case 't':
        {
            string cursoDesejado;
            cout << "Digite o nome do curso: ";
            cin.ignore();
            getline(cin, cursoDesejado);

            Curso *pointCurso = faculdade.buscarCurso(cursoDesejado);
            if (pointCurso != nullptr)
            {
                pointCurso->imprimirListaDeDisciplinas();
                pointCurso->imprimirListaDeProfessores();
                pointCurso->imprimirListaDeAlunos();
            }
            else
            {
                cout << "Curso Não encontrado" << endl;
            }

            break;
        }
        case 's':
        {
            cout << "Saindo...\n";
            break;
        }
        default:
            cout << "Opção inválida!\n";
            break;
        }
    } while (aux != 's');

    return 0;
}
