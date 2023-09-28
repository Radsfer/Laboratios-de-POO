#include <iostream>
#include <string>

int main() {
    std::string texto;
    
    while (std::getline(std::cin, texto)) {
        std::string saidaTexto;
        bool italico = false;
        bool negrito = false;

        for (char c : texto) {
            if (c == '_') {
                if (italico) {
                    saidaTexto += "</i>";
                } else {
                    saidaTexto += "<i>";
                }
                italico = !italico;
            } else if (c == '*') {
                if (negrito) {
                    saidaTexto += "</b>";
                } else {
                    saidaTexto += "<b>";
                }
                negrito = !negrito;
            } else {
                saidaTexto += c;
            }
        }

        std::cout << saidaTexto << std::endl;
    }

    return 0;
}
