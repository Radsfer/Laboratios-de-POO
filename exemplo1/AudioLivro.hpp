#ifndef __AUDIOLIVRO_H__
#define __AUDIOLIVRO_H__
#pragma once
#include "Material.hpp"
#include "DVD.hpp"
#include "Livro.hpp"


class AudioLivro : public DVD, public Livro
{
private:
    std::string narrador;

public:
    std::string getNarrador();
    void setNarrador(std::string nome);
    std::string descricao() override;
    AudioLivro(std::string titulo, std::string autor, int num, std::string minutos, std::string nome);
    ~AudioLivro();
};

#endif // __AUDIOLIVRO_H__