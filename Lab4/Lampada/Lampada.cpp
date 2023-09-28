#include "Lampada.hpp"
#include <string>
#include <iostream>

int Lampada::contador = 0;

Lampada::Lampada() {
    modelo="Indefinido";
    tensao=0; 
    estado="apagada";
    contador++;

}

Lampada::Lampada(std::string modelo, int tensao) {
    this->modelo = modelo;
    this->tensao = tensao;
    estado="apagada";
    contador++;
}

     void Lampada::verificarEstadoLampada(){
        std::cout<<"A lampada esta "<< getEstado()<<std::endl ;

    }

    void Lampada::acenderLampada(){
        if(getEstado()=="apagada"){
            setEstado("acesa");

        }else if(getEstado()=="acesa"){
            std::cout<<"A lampada já esta acesa"<<std::endl;
         
        }
    }
    
    void Lampada::apagarLampada(){
        if(getEstado()=="apagada"){
            std::cout<<"A lampada já esta apagada"<<std::endl;

        }else if(getEstado()=="acesa"){
            setEstado("apagada");
        }
    }



    std::string Lampada::getModelo(){
        return modelo;
    }
    void Lampada::setModelo(const std::string modelo) {
        this->modelo=modelo;
    }

    
    int Lampada::getTensao(){
        return tensao;
    }
    void Lampada::setTensao(int tensao) {
        this->tensao = tensao;
    }

    
    std::string Lampada::getEstado(){
        return estado;
    }
    void Lampada::setEstado(std::string estado) {
        this->estado = estado;
    }

    int Lampada::getContador() {
        return contador;
    }

