#include "Lampada.hpp"
#include <string>
#include <iostream>
#include <cctype>

int main (){
    std::string modelo; int tensao; char continuar;
    
    std::cout<<"Digite o modelo da lampada: ";
    std::cin>>modelo;
    std::cout<<"Digite a tensão da lampada: ";
    std::cin>>tensao;
    
    Lampada lampada(modelo,tensao);
    
    do{
    
    int opcao;
     std::cout<<"\nOque desejda fazer com a lampada\n1-Ver o estado da lampada\n2-Apagar a lampada\n3-Acender a lampada"<<std::endl;
     std::cin>>opcao;
    switch (opcao)
    {
    case 1:
        lampada.verificarEstadoLampada();
        break;

    case 2:
        lampada.apagarLampada();
        break;
    case 3:
        lampada.acenderLampada();
        break;

    default:
        std::cout << "Opção inválida." << std::endl;
        break;
    }
      std::cout << "Deseja fazer outra operação? (S-Sim, N-Não): ";
        std::cin >> continuar;
        continuar = toupper(continuar);
    
    system("clear");

    } while (continuar == 'S');

}