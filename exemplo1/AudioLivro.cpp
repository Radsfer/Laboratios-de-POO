#include "AudioLivro.hpp"

void AudioLivro::setNarrador(std::string nome)
{
    this->narrador = nome;
}

std::string AudioLivro::getNarrador()
{
    return narrador;
}

std::string AudioLivro::descricao()
{
    return Livro::descricao() + "\n" + DVD::descricao() + "\n" + " narrado por " + narrador;
}
AudioLivro::AudioLivro(std::string titulo, std::string autor, int num, std::string minutos, std::string nome) : Material(titulo, autor), Livro(titulo, autor, num), DVD(titulo, autor, minutos), narrador(nome) {}

AudioLivro::~AudioLivro()
{
    
}
