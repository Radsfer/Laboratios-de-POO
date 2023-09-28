#ifndef LAMPADA_HPP
#define LAMPADA_HPP

#include <string>

class Lampada {
private:
    std::string modelo;
    int tensao;
    std::string estado;
    static int contador;
public:
    Lampada();
    Lampada(std::string modelo, int tensao);
   
    static int getContador();
    void verificarEstadoLampada();
    void acenderLampada();
    void apagarLampada();
    
    std::string getModelo();
    void setModelo(std::string modelo);

    int getTensao();
    void setTensao(int tensao);

    std::string getEstado();
    void setEstado(std::string estado);


};

#endif