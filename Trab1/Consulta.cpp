#include "Consulta.hpp"
#include "Paciente.hpp"
#include "Medico.hpp"
class Medico;
class Paciente;
string Consulta::getData(){
    return data;
};

void Consulta::setData(string data){
    this->data=data;
};

string Consulta::getHora(){
    return hora;
};

void Consulta::setHora(string hora){
    this->hora=hora;
};

string Consulta::getCpfPaciente(){
    return cpfPaciente;
};

void Consulta::setCpfPaciente(string cpf){
    this->cpfPaciente=cpf;
};

int Consulta::getCrmMedico(){
    return crmMedico;
};

void Consulta::setCrmMedico(int crm){
    this->crmMedico=crm;
};

void Consulta::imprimirConsulta(){
    cout<<"Data: "<<data<<endl;
    cout<<"Hora: "<<hora<<endl;
};