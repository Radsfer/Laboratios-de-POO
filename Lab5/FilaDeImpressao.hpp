#ifndef FILADEIMPRESSAO_HPP
#define FILADEIMPRESSAO_HPP

#include "Documentos.hpp"

class FilaDeImpressao {
private:
    struct Node {
        Documentos documento;
        Node* next;
        Node(const Documentos& doc) : documento(doc), next(nullptr) {}
    };

    Node* inicio;

public:
    FilaDeImpressao();
    ~FilaDeImpressao();

    void adicionarDocumento(const Documentos& doc);
    Documentos consultarDocumento(int id) const;
    void listarDocumentos() const;
    void atualizarDocumento(const Documentos& novoDocumento);
    bool removerDocumento(int id);
    bool estaVazia() const;
};

#endif 