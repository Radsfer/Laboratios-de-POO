#ifndef __DVD_H__
#define __DVD_H__
#pragma once
#include "Material.hpp"

class DVD : virtual public Material
{
protected:
    std::string duracao;

public:
    std::string getDuracao();
    void setDuracao(std::string minutos);
    std::string descricao() override;
    DVD(std::string titulo,std::string autor, std::string minutos);
   ~DVD();
   
};

#endif // __DVD_H__