#include "Paciente.hpp"

string Paciente::getRelato(){
    return relato;
};

void Paciente::setRelato(string r){
    this->relato=r;
};

string Paciente::getMedicamentoConsumidoRegular(){
    return medicacao;
};

void Paciente::setMedicamentoConsumidaRegular(string m){
    this->medicacao=m;
};

void Paciente::imprimir(){
    imprimirBase();
    cout<<"Relato: "<<relato<<endl;
    cout<<"Medicação frequente: "<<medicacao<<endl;
}