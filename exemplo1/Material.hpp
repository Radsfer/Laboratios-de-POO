#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#pragma once
#include <string>
#include <iostream>


class Material
{
protected:
    std::string titulo;
    std::string autor;

public:
    std::string virtual descricao();

    Material(std::string titulo, std::string autor);
   
   virtual ~Material();
};

#endif // __MATERIAL_H__