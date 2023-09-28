#include "Triangulo.hpp"
#include <cmath>
#include <iostream>



int Triangulo::contador = 0;

Triangulo::Triangulo() {
    lado_a = 1;
    lado_b = 1;
    lado_c = 1;
    contador++;

}

Triangulo::Triangulo(float lado_a, float lado_b, float lado_c) {
    this->lado_a = lado_a;
    this->lado_b = lado_b;
    this->lado_c = lado_c;
    contador++;
}

void Triangulo::verificarTipoTriangulo(){
    
    if((abs(lado_b - lado_c) < lado_a && lado_a < (lado_b + lado_c)) ||
        (abs(lado_a - lado_c) < lado_b && lado_b < (lado_a + lado_c)) ||
        (abs(lado_a - lado_b) < lado_c && lado_c < (lado_a + lado_b))){
        
        std::cout<<"É um triagunlo ";

        if(lado_a==lado_b && lado_a == lado_c){

        std::cout<<"Equilátero!"<<std::endl;

        }else if((lado_a == lado_b && lado_a != lado_c) ||
           (lado_c == lado_b && lado_c != lado_a)||
           (lado_c == lado_a && lado_c != lado_b)){

        std::cout<<"Isósceles!"<<std::endl;

        }else if(lado_a!=lado_b&&lado_b!=lado_c){

        std::cout<<"Escaleno!"<<std::endl;

        }

    }else {
        std::cout<<"Não é um triangulo!"<<std::endl;
    }
}

float Triangulo::getLadoA() {
    return lado_a;
}

void Triangulo::setLadoA(float lado_a) {
    this->lado_a = lado_a;
}

float Triangulo::getLadoB() {
    return lado_b;
}

void Triangulo::setLadoB(float lado_b) {
    this->lado_b = lado_b;
}

float Triangulo::getLadoC() {
    return lado_c;
}

void Triangulo::setLadoC(float lado_c) {
    this->lado_c = lado_c;
}

int Triangulo::getContador() {
    return contador;
}
