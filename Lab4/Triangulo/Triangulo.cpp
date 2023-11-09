#include "Triangulo.hpp"
#include <cmath>
#include <iostream>

using namespace std;


double Triangulo::contador = 0.0;

Triangulo::Triangulo() {
    lado_a = 1.0;
    lado_b = 1.0;
    lado_c = 1.0;
    contador++;

}

Triangulo::Triangulo(double lado_a, double lado_b, double lado_c) {
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

double Triangulo::getLadoA() {
    return lado_a;
}

void Triangulo::setLadoA(double lado_a) {
    this->lado_a = lado_a;
}

double Triangulo::getLadoB() {
    return lado_b;
}

void Triangulo::setLadoB(double lado_b) {
    this->lado_b = lado_b;
}

double Triangulo::getLadoC() {
    return lado_c;
}

void Triangulo::setLadoC(double lado_c) {
    this->lado_c = lado_c;
}

double Triangulo::getContador() {
    return contador;
}
