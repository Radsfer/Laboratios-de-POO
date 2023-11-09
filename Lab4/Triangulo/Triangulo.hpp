#ifndef TRIANGULO_HPP
#define TRIANGULO_HPP

#include <string>

class Triangulo {
private:
    double lado_a;
    double lado_b;
    double lado_c;
    static double contador;
public:
    Triangulo();
    Triangulo(double lado_a, double lado_b, double lado_c);
   
    static double getContador();
    void verificarTipoTriangulo();
    
    
    double getLadoA();
    void setLadoA(double lado_a);

    double getLadoB();
    void setLadoB(double lado_b);

    double getLadoC();
    void setLadoC(double lado_c);


};

#endif