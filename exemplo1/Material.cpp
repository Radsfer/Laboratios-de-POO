#include "Material.hpp"

std::string Material::descricao()
{
  return "A obra " + titulo + "\nEste é um material da biblioteca escrito por " + autor;
}
Material::Material(std::string titulo, std::string autor) : titulo(titulo), autor(autor){}

Material::~Material()
{
  
};


