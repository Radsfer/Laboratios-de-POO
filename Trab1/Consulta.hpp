#ifndef __CONSULTA_H__
#define __CONSULTA_H__
#include <bits/stdc++.h>
using namespace std;
#include "Paciente.hpp"
#include "Medico.hpp"
class Medico;
class Paciente;

class Consulta {
private:
    int numConsulta;
    string data;
    string hora;
    string cpfPaciente;
    int crmMedico;

public:
    
    
    string getData();
    void setData(string data);
    string getHora();
    void setHora(string hora);
    string getCpfPaciente();
    void setCpfPaciente(string cpf);
    int getCrmMedico();
    void setCrmMedico(int crm);

    
    void imprimirConsulta();

    Consulta(string data,string hora,string cpf,int crm):data(data), 
    hora(hora),cpfPaciente(cpf),crmMedico(crm){};

};


#endif // __CONSULTA_H__