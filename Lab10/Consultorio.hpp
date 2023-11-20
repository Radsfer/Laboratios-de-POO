#ifndef __CONSULTORIO_H__
#define __CONSULTORIO_H__
#include <bits/stdc++.h>
using namespace std;

#include "Paciente.hpp"
#include "Medico.hpp"
#include "Consulta.hpp"
#include "Excecoes.hpp"

class Medico;
class Paciente;
class Consulta;

class Consultorio
{
private:
    vector<Medico> medicos;
    vector<Paciente> pacientes;
    vector<Consulta> consultas;
    int contPaciente;
    int telefone;
    string endereco;
    string nome;

public:
    Pessoa cadastrarPessoa();
    void cadastrarPaciente(Paciente p);
    void excluirConsultasDoPaciente(string cpfPaciente);
    void removerPaciente(string cpf);
    void cadastrarMedico(Medico m);
    void excluirConsultasDoMedico(int crmMedico);
    void removerMedico(int crm);
    void cadastrarConsulta(Consulta c);
    void removerConsulta(string cpf, string data);
    void imprimirConsultaPacienteMedico(Consulta c);
    void imprimirListaPacientes();
    void imprimirListaMedicos();
    void imprimirListaConsultas();
    void procurarConsulta(string cpfPaciente);
    Paciente procurarPacientePorCPF(string cpfPaciente);
    Medico procurarMedicosPorCRM(int crm);
    void listarMedicosEspecialistas(string especialidade);

    int getContPaciente();
    void setContPaciente(int cont);
    int getTelefone();
    void setTelefone(int telefone);
    string getEndereco();
    void setEndereco(string endereco);
    string getNome();
    void setNome(string nome);

    Consultorio()
    {
        nome = "Trabalho 1";
        endereco = "Rua do limoeiro, 123";
        telefone = 12345678;
        contPaciente = 0;
    };
    Consultorio(string nome, string endereco, int telefone, int contPaciente) : nome(nome), endereco(endereco), telefone(telefone), contPaciente(contPaciente) {}
};

#endif // __CONSULTORIO_H__