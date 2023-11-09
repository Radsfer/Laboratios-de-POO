#ifndef __LIVRO_H__
#define __LIVRO_H__

#pragma once
#include "Material.hpp"


class Livro : virtual public Material
{
protected:
    int num_paginas;

public:
    int getNumPaginas();
    void setNumPaginas(int num);
    std::string descricao() override;
    Livro(std::string titulo, std::string autor, int num);
    ~Livro();
};

#endif // __LIVRO_H__