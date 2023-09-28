#include <iostream>
#include <cmath>
#include "Triangulo.hpp"
int main (){

    float lado_a, lado_b, lado_c;

    std::cout<<"Digite o valor do lado A: ";
    std::cin>> lado_a;
    std::cout<<"Digite o valor do lado B: ";
    std::cin>> lado_b;
    std::cout<<"Digite o valor do lado C: ";
    std::cin>> lado_c;

    Triangulo triangulo (lado_a,lado_b, lado_c);
    
    triangulo.verificarTipoTriangulo();


}