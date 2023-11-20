#include "Medico.hpp"


int Medico::getCrm(){
    return crm;
};

void Medico::setCrm(int crm){
    this->crm=crm;
};

string Medico::getEspecialidade(){
    return especialidade;
};

void Medico::setEspecialidade(string especialidade){
    this->especialidade=especialidade;
};


void Medico::imprimir(){
    imprimirBase();
    cout<<"CRM: "<<crm<<endl;
    cout<<"Especialidade: "<<especialidade<<endl;
};