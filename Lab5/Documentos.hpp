#ifndef DOCUMENTOS_HPP
#define DOCUMENTOS_HPP

#include <string>

class Documentos {
private:
    int Id_documentos;
    std::string NomeDocumento;
    int QuantidadePaginas;
    int PrioridadeNivel;

public:
    Documentos(int Id_documentos, std::string NomeDocumento, int QuantidadePaginas, int PrioridadeNivel);

    int getId_documentos() const;
    void setId_documentos(int Id_documentos);

    std::string getNomeDocumento();
    void setNomeDocumento(std::string NomeDocumento);

    int getQuantidadePaginas() const;
    void setQuantidadePaginas(int QuantidadePaginas);

    int getPrioridadeNivel() const;
    void setPrioridadeNivel(int PrioridadeNivel);
};

#endif
