#include <iostream>
#include "Corrida.hpp"

int main() {
    std::string modelo_carro, motorizacao_carro, fabricante_veiculo, nome_motorista;
    float km_inicial, km_final;

    std::cout << "Modelo do carro: ";
    std::cin >> modelo_carro;
    std::cout << "Motorizacao do carro: ";
    std::cin >> motorizacao_carro;
    std::cout << "Fabricante do veiculo: ";
    std::cin >> fabricante_veiculo;
    std::cout << "Nome do motorista: ";
    std::cin >> nome_motorista;
    std::cout << "Quilometragem inicial: ";
    std::cin >> km_inicial;
    std::cout << "Quilometragem final: ";
    std::cin >> km_final;

    Corrida corrida(modelo_carro, motorizacao_carro, fabricante_veiculo,
                    nome_motorista, km_inicial, km_final);

    std::cout << "\nDados da corrida:" << std::endl;
    std::cout << "Modelo do carro: " << corrida.getModeloCarro() << std::endl;
    std::cout << "Motorizacao do carro: " << corrida.getMotorizacaoCarro() << std::endl;
    std::cout << "Fabricante do veiculo: " << corrida.getFabricanteVeiculo() << std::endl;
    std::cout << "Nome do motorista: " << corrida.getNomeMotorista() << std::endl;
    std::cout << "Quilometragem inicial: " << corrida.getKmInicial() << std::endl;
    std::cout << "Quilometragem final: " << corrida.getKmFinal() << std::endl;
    std::cout << "Quilometragem percorrida: " << corrida.calcularQuilometragemPercorrida() << std::endl;
    std::cout << "Valor a ser pago: " << corrida.valorFinal() << std::endl;

    return 0;
}
