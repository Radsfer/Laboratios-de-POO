#include "Consultorio.hpp"
#include "Consulta.hpp"
#include "Paciente.hpp"
#include "Medico.hpp"
#include "Excecoes.hpp"

class Medico;
class Paciente;
class Consulta;

Pessoa Consultorio::cadastrarPessoa()
{
    string nome;
    char sexo;
    string endereco;
    string cpf;
    int telefone;
    int identidade;

    Pessoa novaPessoa;

    cout << "Digite o nome da pessoa: ";
    getline(cin, nome);

    novaPessoa.setNome(nome);

    do
    {
        try
        {
            cout << "Digite o sexo\nM-Masculino\nF-Feminino\nEscolha: ";
            cin >> sexo;
            sexo = toupper(sexo);
            cin.ignore();


            novaPessoa.setSexo(sexo); 

            break;
        }
        catch (const ExcecaoSexoInvalido &e)
        {
        
            cerr << "Erro: " << e.what() << endl;
        }
    } while (true);

    cout << "Digite o endereco: ";
    getline(cin, endereco);
    novaPessoa.setEndereco(endereco);

    cout << "Digite o CPF: ";
    getline(cin, cpf);
    novaPessoa.setCpf(cpf);

    cout << "Digite o telefone: ";
    cin >> telefone;
    novaPessoa.setTelefone(telefone);
    cout << "Digite a identidade: ";
    cin >> identidade;
    cin.ignore();
    novaPessoa.setIdentidade(identidade);

    return novaPessoa;
};

void Consultorio::cadastrarPaciente(Paciente p)
{
    string verificar = p.getCpf();
    bool permitir = false;
    for (int i = 0; i < pacientes.size(); i++)
    {
        if (pacientes[i].getCpf() == verificar)
        {
            permitir = true;
            break;
        }
    }
    if (!permitir)
    {
        pacientes.push_back(p);
        setContPaciente(pacientes.size());
        cout << "Paciente cadastrado com sucesso!" << endl;
    }
    else
    {
        cout << "AVISO: CPF já registrado!\nCadastro cancelado!" << endl;
    }
};
void Consultorio::excluirConsultasDoPaciente(string cpfPaciente)
{
    for (int i = 0; i < consultas.size(); i++)
    {
        if (consultas[i].getCpfPaciente() == cpfPaciente)
        {
            consultas.erase(consultas.begin() + i);
        }
    }
}

void Consultorio::removerPaciente(string cpf)
{
    bool deletado = false;
    for (int i = 0; i < pacientes.size(); i++)
    {
        if (pacientes[i].getCpf() == cpf)
        {
            excluirConsultasDoPaciente(pacientes[i].getCpf());
            pacientes.erase(pacientes.begin() + i);
            cout << "Paciente removido!" << endl;
            deletado = true;
            break;
        }
    }
    if (!deletado)
    {
        throw ExcecaoPacienteInexistente();
    }
}

void Consultorio::cadastrarMedico(Medico m)
{
    int crmVerificar = m.getCrm();
    string cpfVeirifcar = m.getCpf();
    bool verificar = false;
    for (int i = 0; i < medicos.size(); i++)
    {
        if (medicos[i].getCrm() == crmVerificar && medicos[i].getCpf() == cpfVeirifcar)
        {
            verificar = true;
            break;
        }
    }
    if (!verificar)
    {
        medicos.push_back(m);
        cout << "Medico cadastrado com sucesso!" << endl;
    }
    else
    {
        cout << "AVISO: Medico já está cadastrados!\nCancelando cadastro ... " << endl;
    }
};

void Consultorio::excluirConsultasDoMedico(int crmMedico)
{
    for (int i = 0; i < consultas.size(); i++)
    {
        if (consultas[i].getCrmMedico() == crmMedico)
        {
            consultas.erase(consultas.begin() + i);
        }
    }
};

void Consultorio::removerMedico(int crm)
{
    bool removido = false;
    for (int i = 0; i < medicos.size(); i++)
    {
        if (medicos[i].getCrm() == crm)
        {
            excluirConsultasDoMedico(medicos[i].getCrm());
            medicos.erase(medicos.begin() + i);
            cout << "Médico removido!" << endl;
            removido = true;
            break;
        }
    }
    if (!removido)
    {
        throw ExcecaoMedicoInexistente();
    }
};

void Consultorio::cadastrarConsulta(Consulta c)
{
    string verificarData = c.getData();
    string verificarHora = c.getHora();
    string verificarPaciente = c.getCpfPaciente();
    int verificarMedico = c.getCrmMedico();

    bool pacienteJaTemConsulta = false;
    bool medicoOcupado = false;

    for (int i = 0; i < consultas.size(); i++)
    {
        if (consultas[i].getData() == verificarData && consultas[i].getHora() == verificarHora)
        {
            medicoOcupado = (consultas[i].getCrmMedico() == verificarMedico);
            pacienteJaTemConsulta = (consultas[i].getCpfPaciente() == verificarPaciente);

            if (pacienteJaTemConsulta)
            {
                cout << "Paciente já tem uma consulta nesse horário!" << endl;
                break;
            }
            else if (medicoOcupado)
            {
                cout << "Médico ocupado nesse horário!" << endl;
                break;
            }
        }
    }

    if (!pacienteJaTemConsulta && !medicoOcupado)
    {
        consultas.push_back(c);
        cout << "Consulta marcada!" << endl;
    }
}

void Consultorio::removerConsulta(string cpfPaciente,string dataConsulta)
{
    vector<Consulta> consultasDoPaciente;
    for (int i=0; i<consultas.size();i++)
    {
        if (consultas[i].getCpfPaciente() == cpfPaciente && consultas[i].getData()==dataConsulta)
        {
            consultasDoPaciente.push_back(consultas[i]);
        }
    }

    if (consultasDoPaciente.empty())
    {
        throw ExcecaoConsultaInexistente(cpfPaciente, dataConsulta);
    }

    cout << "Consultas do paciente no dia: " << endl;
    for (int i=0; i<consultasDoPaciente.size();i++)
    {
        consultasDoPaciente[i].imprimirConsulta();
        imprimirConsultaPacienteMedico(consultasDoPaciente[i]);
        cout << "--------------------------------" << endl;
    }

    string horaConsulta;
    cout << "Digite a hora da consulta que deseja remover (HH:MM): ";
    getline(cin, horaConsulta);

    bool consultaEncontrada = false;
    for (auto it = consultas.begin(); it != consultas.end(); ++it)
    {
        if (it->getCpfPaciente() == cpfPaciente &&
            it->getHora() == horaConsulta)
        {
            it = consultas.erase(it);
            consultaEncontrada = true;
            cout << "Consulta desmarcada!" << endl;
            break;
        }
    }

    if (!consultaEncontrada)
    {
        throw ExcecaoConsultaInexistente(cpfPaciente, dataConsulta);
    }
}


void Consultorio::imprimirListaPacientes()
{
    for (int i = 0; i < pacientes.size(); i++)
    {
        pacientes[i].imprimir();
        cout << "--------------------------------" << endl;
    }
};
void Consultorio::imprimirListaMedicos()
{
    for (int i = 0; i < medicos.size(); i++)
    {
        medicos[i].imprimir();
        cout << "--------------------------------" << endl;
    }
};

void Consultorio::imprimirConsultaPacienteMedico(Consulta c)
{
    for (int j = 0; j < medicos.size(); j++)
    {
        if (medicos[j].getCrm() == c.getCrmMedico())
        {
            cout << "Medico: " << medicos[j].getNome() << endl;
            cout << "Especialidade: " << medicos[j].getEspecialidade() << endl;
            break;
        }
    }
    for (int k = 0; k < pacientes.size(); k++)
    {
        if (pacientes[k].getCpf() == c.getCpfPaciente())
        {
            cout << "Paciente: " << pacientes[k].getNome() << endl;
            cout << "Relato: " << pacientes[k].getRelato() << endl;
            break;
        }
    }
};

void Consultorio::imprimirListaConsultas()
{
    for (int i = 0; i < consultas.size(); i++)
    {
        consultas[i].imprimirConsulta();
        imprimirConsultaPacienteMedico(consultas[i]);
        cout << "--------------------------------" << endl;
    }
};

void Consultorio::procurarConsulta(string cpfPaciente)
{
    cout << "Escolha uma opção:" << endl;
    cout << "1 - Mostrar todas as consultas do paciente" << endl;
    cout << "2 - Mostrar consulta em uma data e hora específicas" << endl;

    int opcao;
    cin >> opcao;
    cin.ignore();
    if (opcao == 1)
    {
        bool temConsultas = false;
        for (int i = 0; i < consultas.size(); i++)
        {
            if (consultas[i].getCpfPaciente() == cpfPaciente)
            {
                consultas[i].imprimirConsulta();
                imprimirConsultaPacienteMedico(consultas[i]);
                cout << "--------------------------------" << endl;
                temConsultas = true;
            }
        }
        cout << (!(temConsultas) ? "Não tem consultas marcadas ainda!\n" : "") << endl;
    }
    else if (opcao == 2)
    {
        string data, hora;
        cout << "Digite a data (DD/MM/AAAA): ";
        getline(cin, data);
        cout << "Digite a hora (HH:MM): ";
        getline(cin, hora);

        for (int i = 0; i < consultas.size(); i++)
        {
            if (consultas[i].getCpfPaciente() == cpfPaciente &&
                consultas[i].getData() == data && consultas[i].getHora() == hora)
            {
                consultas[i].imprimirConsulta();
                imprimirConsultaPacienteMedico(consultas[i]);
                cout << "--------------------------------" << endl;
                return;
            }
        }

        cout << "Nenhuma consulta encontrada na data e hora especificadas." << endl;
    }
    else
    {
        cout << "Opção inválida." << endl;
    }
};

Paciente Consultorio::procurarPacientePorCPF(string cpf)
{
    for (int i = 0; i < pacientes.size(); i++)
    {
        if (pacientes[i].getCpf() == cpf)
        {
            return pacientes[i];
        }
    }
    return Paciente();
};

Medico Consultorio::procurarMedicosPorCRM(int crm)
{
    for (int i = 0; i < medicos.size(); i++)
    {
        if (medicos[i].getCrm() == crm)
        {
            return medicos[i];
        }
    }
    return Medico();
};

void Consultorio::listarMedicosEspecialistas(string especialidade)
{
    cout << "Medicos especialistas em " << especialidade << " disponíveis:" << endl;

    bool encontrouEspecialistas = false;

    for (int i = 0; i < medicos.size(); i++)
    {
        if (medicos[i].getEspecialidade() == especialidade)
        {
            encontrouEspecialistas = true;
            cout << "Nome: " << medicos[i].getNome() << endl;
            cout << "CRM: " << medicos[i].getCrm() << endl;
            cout << "Ocupado nos seguintes horários: " << endl;
            bool temConsultas = false;
            for (int j = 0; j < consultas.size(); j++)
            {
                if (consultas[j].getCrmMedico() == medicos[i].getCrm())
                {
                    consultas[j].imprimirConsulta();
                    temConsultas = true;
                }
            }
            cout << (!(temConsultas) ? "Não tem consultas marcadas ainda!\n" : "") << endl;
            cout << "--------------------------------" << endl;
        }
    }

    if (!encontrouEspecialistas)
    {
        cout << "Não tem medicos com essa especialidade" << endl;
    }
}

int Consultorio::getContPaciente()
{
    return contPaciente;
};

void Consultorio::setContPaciente(int cont)
{
    this->contPaciente = cont;
};

int Consultorio::getTelefone()
{
    return telefone;
};

void Consultorio::setTelefone(int telefone)
{
    this->telefone = telefone;
};

string Consultorio::getEndereco()
{
    return endereco;
};

void Consultorio::setEndereco(string endereco)
{
    this->endereco = endereco;
};

string Consultorio::getNome()
{
    return nome;
};

void Consultorio::setNome(string nome)
{
    this->nome = nome;
};
