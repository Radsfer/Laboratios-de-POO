#include "Excecoes.hpp"

const char *ExcecaoSexoInvalido::what() const noexcept
{
    return "Sexo inválido. Favor digitar M ou F";
}

const char *ExcecaoPacienteInexistente::what() const noexcept
{
    return "Impossível remover paciente. CPF não existe";
}

const char *ExcecaoMedicoInexistente::what() const noexcept
{
    return "Impossível remover médico. CRM não existe";
}

void ExcecaoConsultaInexistente::construirMensagem()

{
    mensagem = "Impossível remover Consulta. Paciente " + cpf +
               " não tem consulta agendada para a data " + data;
}

const char *ExcecaoConsultaInexistente::what() const noexcept
{

    return mensagem.c_str();
}
