#include "Documentos.hpp"

Documentos::Documentos(int Id_documentos, std::string NomeDocumento, int QuantidadePaginas, int PrioridadeNivel){
this->Id_documentos=Id_documentos;
this->NomeDocumento=NomeDocumento;
this->QuantidadePaginas=QuantidadePaginas;
this->PrioridadeNivel=PrioridadeNivel;

};

int Documentos::getId_documentos() const {
    return Id_documentos;
}

void Documentos::setId_documentos(int Id_documentos) {
    this->Id_documentos = Id_documentos;
}

std::string Documentos::getNomeDocumento() {
    return NomeDocumento;
}

void Documentos::setNomeDocumento(std::string NomeDocumento) {
    this->NomeDocumento = NomeDocumento;
}

int Documentos::getQuantidadePaginas() const {
    return QuantidadePaginas;
}

void Documentos::setQuantidadePaginas(int QuantidadePaginas) {
    this->QuantidadePaginas = QuantidadePaginas;
}

int Documentos::getPrioridadeNivel() const {
    return PrioridadeNivel;
}

void Documentos::setPrioridadeNivel(int PrioridadeNivel) {
    this->PrioridadeNivel = PrioridadeNivel;
}
