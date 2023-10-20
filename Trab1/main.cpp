#include <iostream>
#include <bits/stdc++.h>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "Consulta.hpp"
#include "Consultorio.hpp"

using namespace std;

int main()
{
    Consultorio consultorio;
    Paciente pacienteNulo = Paciente();
    int opcao;
    //Habib essa parte é para auxiliar nos testes de forma mais rapida como foi dito no relatório
    // Medico medico1 = Medico(Pessoa("Dr. João", 'M', "Rua A", "12345678901", 12345, 1), 123, "Cardiologia");
    // Medico medico2 = Medico(Pessoa("Dra. Maria", 'F', "Rua B", "98765432109", 54321, 2), 321, "Ortopedia");

    // Paciente paciente1 = Paciente(Pessoa("João da Silva", 'M', "Rua X", "11122233344", 9999, 1234), "Dor de cabeça", "Aspirina");
    // Paciente paciente2 = Paciente(Pessoa("Maria da Silva", 'F', "Rua Y", "44433322211", 8888, 4321), "Dor nas costas", "Relaxante muscular");

    // Consulta consulta1 = Consulta("10/10/2023", "10:00", paciente1.getCpf(), medico1.getCrm());
    // Consulta consulta2 = Consulta("11/10/2023", "11:00", paciente2.getCpf(), medico2.getCrm());
    // Consulta consulta3 = Consulta("10/10/2023", "12:00", paciente1.getCpf(), medico1.getCrm());

    // consultorio.cadastrarMedico(medico1);
    // consultorio.cadastrarMedico(medico2);
    // consultorio.cadastrarPaciente(paciente1);
    // consultorio.cadastrarPaciente(paciente2);
    // consultorio.cadastrarConsulta(consulta1);
    // consultorio.cadastrarConsulta(consulta2);
    // consultorio.cadastrarConsulta(consulta3);

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Cadastrar um médico" << endl;
        cout << "2. Cadastrar um paciente" << endl;
        cout << "3. Cadastrar uma consulta" << endl;
        cout << "4. Imprimir dados do paciente" << endl;
        cout << "5. Imprimir dados do médico" << endl;
        cout << "6. Imprimir dados de todos médicos" << endl;
        cout << "7. Imprimir dados de todos pacientes" << endl;
        cout << "8. Imprimir todas as consultas" << endl;
        cout << "9. Imprimir uma consulta específica" << endl;
        cout << "10. Remover médico" << endl;
        cout << "11. Remover paciente" << endl;
        cout << "12. Remover consulta" << endl;
        cout << "13. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();
        cout << endl;
        switch (opcao)
        {
        case 1:
        {
            int crmMedico;
            string especialidadeMedico;

            Pessoa cadastroPessoa = consultorio.cadastrarPessoa();
            cout << "Digite o CRM: ";
            cin >> crmMedico;
            cin.ignore();
            cout << "Digite a especialidade: ";
            getline(cin, especialidadeMedico);

            Medico novoMedico = Medico(cadastroPessoa, crmMedico, especialidadeMedico);
            consultorio.cadastrarMedico(novoMedico);
            break;
        }
        case 2:
        {
            string relatoPaciente, medicacaoPaciente;
            Pessoa cadastroPessoa = consultorio.cadastrarPessoa();
            cout << "Digite o relato: ";
            getline(cin, relatoPaciente);
            cout << "Digite a medicacao: ";
            getline(cin, medicacaoPaciente);

            Paciente novoPaciente(cadastroPessoa, relatoPaciente, medicacaoPaciente);
            consultorio.cadastrarPaciente(novoPaciente);
            break;
        }
        case 3:
        {
            string cpf, especialidade;
            cout << "Digite o cpf do paciente: ";
            getline(cin, cpf);
            Paciente pacienteConsultado = consultorio.procurarPacientePorCPF(cpf);

            if (pacienteConsultado.getCpf() == pacienteNulo.getCpf())
            {
                cout << "Paciente não encontrado!" << endl;
            }
            else
            {
                int crm;
                cout << "Digite a especialidade do médico que deseja procurar: ";
                getline(cin, especialidade);
                consultorio.listarMedicosEspecialistas(especialidade);

                cout << "AVISO: Se aparaceu que não a medicos com essa especialidade digite 0 para sair!\nDigite o CRM do médico que deseja consultar: ";
                cin >> crm;
                cin.ignore();
                Medico medicoDaConsulta = consultorio.procurarMedicosPorCRM(crm);
                string dataDaConsulta;
                string horaDaConsulta;
                if (crm == 0)
                {
                    cout << "Cadastro cancelado!" << endl;
                }
                else
                {

                    bool dataDaConsultaValida = false;

                    while (!dataDaConsultaValida)
                    {
                        cout << "Digite a dataDaConsulta (DD/MM/AAAA): ";
                        cin >> dataDaConsulta;

                        if (dataDaConsulta.size() == 10 && dataDaConsulta[2] == '/' && dataDaConsulta[5] == '/')
                        {
                            bool formatoValido = true;
                            for (int i = 0; i < 10; i++)
                            {
                                if (i != 2 && i != 5 && !isdigit(dataDaConsulta[i]))
                                {
                                    formatoValido = false;
                                    break;
                                }
                            }

                            if (formatoValido)
                            {
                                dataDaConsultaValida = true;
                            }
                        }

                        if (!dataDaConsultaValida)
                        {
                            cout << "Formato de dataDaConsulta inválido. Use o formato DD/MM/AAAA." << endl;
                        }
                    }

                    bool horaDaConsultaValida = false;

                    while (!horaDaConsultaValida)
                    {
                        cout << "Digite a horaDaConsulta (HH:MM): ";
                        cin >> horaDaConsulta;

                        if (horaDaConsulta.size() == 5 && horaDaConsulta[2] == ':')
                        {
                            int horaDaConsultas = stoi(horaDaConsulta.substr(0, 2));
                            int minutos = stoi(horaDaConsulta.substr(3, 2));

                            if (horaDaConsultas >= 8 && horaDaConsultas <= 18 && minutos >= 0 && minutos <= 59)
                            {
                                horaDaConsultaValida = true;
                            }
                        }

                        if (!horaDaConsultaValida)
                        {
                            cout << "Formato de horaDaConsulta inválido. Use o formato HH:MM e esteja dentro do horário de 08:00 até as 18:00." << endl;
                        }
                    }
                }
                Consulta novaConsulta = Consulta(dataDaConsulta, horaDaConsulta, pacienteConsultado.getCpf(), medicoDaConsulta.getCrm());
                consultorio.cadastrarConsulta(novaConsulta);
            }
            break;
        }
        case 4:
        {
            string cpfConsulta;
            cout << "Digite o cpf do paciente: ";
            getline(cin, cpfConsulta);
            Paciente pacienteProcurado = consultorio.procurarPacientePorCPF(cpfConsulta);
            if (pacienteProcurado.getCpf() == pacienteNulo.getCpf())
            {
                cout << "Paciente não encontrado!" << endl;
            }
            else
            {
                cout << "--------------------------------" << endl;
                pacienteProcurado.imprimir();
                cout << "--------------------------------" << endl;
            }
            break;
        }

        case 5:
        {
            int crmConsulta;
            cout << "Digite o CRM do médico: ";
            cin >> crmConsulta;
            cin.ignore();
            Medico medicoProcurado = consultorio.procurarMedicosPorCRM(crmConsulta);
            if (medicoProcurado.getCrm() == 0)
            {
                cout << "Médico não encontrado!" << endl;
            }
            else
            {
                cout << "--------------------------------" << endl;
                medicoProcurado.imprimir();
                cout << "--------------------------------" << endl;
            }
            break;
        }
        case 6:
        {
            consultorio.imprimirListaMedicos();
            break;
        }
        case 7:
        {
            consultorio.imprimirListaPacientes();
            break;
        }

        case 8:
        {
            consultorio.imprimirListaConsultas();
            break;
        }

        case 9:
        {
            string cpfConsulta;
            cout << "Digite o cpf do paciente: ";
            getline(cin, cpfConsulta);
            Paciente pacienteProcurado = consultorio.procurarPacientePorCPF(cpfConsulta);
            if (pacienteProcurado.getCpf() == pacienteNulo.getCpf())
            {
                cout << "Paciente não encontrado!" << endl;
            }
            else
            {
                consultorio.procurarConsulta(cpfConsulta);
            }
            break;
        }

        case 10:
        {
            int crmRemover = 0;
            cout << "Digite o CRM do medico que deseja remover: ";
            cin >> crmRemover;
            cin.ignore();
            consultorio.removerMedico(crmRemover);
            break;
        }

        case 11:
        {
            string cpfRemover;
            cout << "Digite o CPF do paciente que deseja remover: ";
            getline(cin, cpfRemover);
            consultorio.removerPaciente(cpfRemover);
            break;
        }

        case 12:
        {
            string cpfRemover;
            cout << "Digite o CPF do paciente que deseja remover: ";
            getline(cin, cpfRemover);
            int crmRemover = 0;
            cout << "Digite o CRM do medico que deseja remover: ";
            cin >> crmRemover;
            cin.ignore();
            consultorio.removerConsulta(cpfRemover, crmRemover);
            break;
        }

        case 13:
            cout << "Saindo do programa..." << endl;
            break;

        default:
            cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 13);

    return 0;
}
