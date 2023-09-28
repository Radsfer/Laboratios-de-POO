#ifndef TRIANGULO_HPP
#define TRIANGULO_HPP

#include <string>

class Triangulo {
private:
    float lado_a;
    float lado_b;
    float lado_c;
    static int contador;
public:
    Triangulo();
    Triangulo(float lado_a, float lado_b, float lado_c);
   
    static int getContador();
    void verificarTipoTriangulo();
    
    
    float getLadoA();
    void setLadoA(float lado_a);

    float getLadoB();
    void setLadoB(float lado_b);

    float getLadoC();
    void setLadoC(float lado_c);


};

#endif