#ifndef __EXCECOES_H__
#define __EXCECOES_H__

#pragma once

#include <stdexcept>
#include <string>
#include <cstring>

class ExcecaoSexoInvalido : public std::exception {
public:
    const char* what() const noexcept override;
};

class ExcecaoPacienteInexistente : public std::exception {
public:
    const char* what() const noexcept override;
};

class ExcecaoMedicoInexistente : public std::exception {
public:
    const char* what() const noexcept override;
};

class ExcecaoConsultaInexistente : public std::exception {
private:
    std::string  cpf;
    std::string data;
    std::string mensagem;

public:
    ExcecaoConsultaInexistente(const std::string  cpf, const std::string& data)
        : cpf(cpf), data(data) {
            construirMensagem();
        }

    const char* what() const noexcept override;

    void construirMensagem();
};


#endif // __EXCECOES_H__