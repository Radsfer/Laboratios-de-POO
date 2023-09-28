#include "Corrida.hpp"

Corrida::Corrida(std::string modelo_carro, std::string motorizacao_carro,
                 std::string fabricante_veiculo, std::string nome_motorista,
                 float km_inicial, float km_final)
    : modelo_carro(modelo_carro), motorizacao_carro(motorizacao_carro),
      fabricante_veiculo(fabricante_veiculo), nome_motorista(nome_motorista),
      km_inicial(km_inicial), km_final(km_final) {}

float Corrida::calcularQuilometragemPercorrida() {
    return km_final - km_inicial;
}

float Corrida::valorFinal() {
    float quilometragem_percorrida = calcularQuilometragemPercorrida();
    float valor_por_km = 3.75;
    return quilometragem_percorrida * valor_por_km;
}

std::string Corrida::getModeloCarro() {
    return modelo_carro;
}

void Corrida::setModeloCarro(std::string modelo_carro) {
    this->modelo_carro = modelo_carro;
}

std::string Corrida::getMotorizacaoCarro() {
    return motorizacao_carro;
}

void Corrida::setMotorizacaoCarro(std::string motorizacao_carro) {
    this->motorizacao_carro = motorizacao_carro;
}

std::string Corrida::getFabricanteVeiculo() {
    return fabricante_veiculo;
}

void Corrida::setFabricanteVeiculo(std::string fabricante_veiculo) {
    this->fabricante_veiculo = fabricante_veiculo;
}

std::string Corrida::getNomeMotorista() {
    return nome_motorista;
}

void Corrida::setNomeMotorista(std::string nome_motorista) {
    this->nome_motorista = nome_motorista;
}

float Corrida::getKmInicial() {
    return km_inicial;
}

void Corrida::setKmInicial(float km_inicial) {
    this->km_inicial = km_inicial;
}

float Corrida::getKmFinal() {
    return km_final;
}

void Corrida::setKmFinal(float km_final) {
    this->km_final = km_final;
}
