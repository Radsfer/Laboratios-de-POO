#include "Livro.hpp"
int Livro::getNumPaginas()
{
    return num_paginas;
}

void Livro::setNumPaginas(int num)
{
    this->num_paginas = num;
}

std::string Livro::descricao()
{
    return Material::descricao() + ", com número de páginas de " + std::to_string(num_paginas);
}

Livro::Livro(std::string titulo, std::string autor, int num) : Material(titulo, autor), num_paginas(num) {}

Livro::~Livro()
{
    
}
