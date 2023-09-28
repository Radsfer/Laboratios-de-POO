#ifndef CORRIDA_HPP
#define CORRIDA_HPP

#include <string>

class Corrida {
private:
    std::string modelo_carro;
    std::string motorizacao_carro;
    std::string fabricante_veiculo;
    std::string nome_motorista;
    float km_inicial;
    float km_final;

public:
    Corrida(std::string modelo_carro, std::string motorizacao_carro,
           std::string fabricante_veiculo, std::string nome_motorista,
           float km_inicial, float km_final);

    float calcularQuilometragemPercorrida();
    float valorFinal();

    // Getters e setters
    std::string getModeloCarro();
    void setModeloCarro(std::string modelo_carro);

    std::string getMotorizacaoCarro();
    void setMotorizacaoCarro(std::string motorizacao_carro);

    std::string getFabricanteVeiculo();
    void setFabricanteVeiculo(std::string fabricante_veiculo);

    std::string getNomeMotorista();
    void setNomeMotorista(std::string nome_motorista);

    float getKmInicial();
    void setKmInicial(float km_inicial);

    float getKmFinal();
    void setKmFinal(float km_final);
};

#endif

