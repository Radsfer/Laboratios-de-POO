#include "DVD.hpp"
std::string DVD::getDuracao()
{
    return duracao;
}

void DVD::setDuracao(std::string minutos)
{
    this->duracao = minutos;
}

std::string DVD::descricao()
{
    return Material::descricao() + ", com duração de " + duracao;
}
DVD::DVD(std::string titulo, std::string autor, std::string minutos) : Material(titulo, autor), duracao(minutos) {}

DVD::~DVD()
{
    
}
