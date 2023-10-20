#include "Consultorio.hpp"
#include "Consulta.hpp"
#include "Paciente.hpp"
#include "Medico.hpp"
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

    nome = "";
    sexo = ' ';
    endereco = "";
    cpf = "";
    telefone = 0;
    identidade = 0;

    cout << "Digite o nome da pessoa: ";
    getline(cin, nome);
    while (true)
    {
        bool valido = false;
        cout << "Digite o sexo\nM-Masculino\nF-Feminino\nN-Não declarar\nEscolha: ";
        cin >> sexo;
        sexo = toupper(sexo);
        cin.ignore();
        switch (sexo)
        {
        case 'M':
            break;
        case 'F':
            break;
        case 'N':
            break;
        default:
            cout << "Digite uma opção válida!" << endl;
            valido = true;
            break;
        }
        if (!valido)
        {
            break;
        }
    }

    cout << "Digite o endereco: ";
    getline(cin, endereco);

    cout << "Digite o CPF: ";
    getline(cin, cpf);

    cout << "Digite o telefone: ";
    cin >> telefone;

    cout << "Digite a identidade: ";
    cin >> identidade;
    cin.ignore();

    Pessoa novaPessoa(nome, sexo, endereco, cpf, telefone, identidade);

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
    for (int i = 0; i < consultas.size();i++)
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
        cout << "CPF não encontrado!" << endl;
    }
};

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
    for (int i = 0; i < consultas.size();i++)
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
            cout << "Medico removido!" << endl;
            removido = true;
            break;
        }
    }
    if (!removido)
    {
        cout << "CRM não encontrado!" << endl;
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
            // Verificar se a data e hora já estão ocupadas
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

void Consultorio::removerConsulta(string cpfPaciente, int crmMedico)
{
    if (consultas.empty())
    {
        cout << "Não existem consultas ainda!" << endl;
        return;
    }

    string dataConsulta, horaConsulta;
    bool consultaEncontrada = false;

    cout << "Digite a data da consulta (DD/MM/AAAA): ";
    getline(cin, dataConsulta);
    cout << "Digite a hora da consulta (HH:MM): ";
    getline(cin, horaConsulta);

    for (int i = 0; i < consultas.size(); i++)
    {
        if (consultas[i].getCpfPaciente() == cpfPaciente &&
            consultas[i].getCrmMedico() == crmMedico &&
            consultas[i].getData() == dataConsulta &&
            consultas[i].getHora() == horaConsulta)
        {
            consultas.erase(consultas.begin() + i);
            consultaEncontrada = true;
            cout << "Consulta desmarcada!" << endl;
            break;
        }
    }

    if (!consultaEncontrada)
    {
        cout << "Nenhuma consulta encontrada na data e hora especificadas." << endl;
    }
};

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
        cout << !temConsultas ? "Não tem consultas marcadas ainda!\n" : "";
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
            cout << !temConsultas ? "Não tem consultas marcadas ainda!\n" : "";
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
