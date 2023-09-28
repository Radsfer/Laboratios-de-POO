#include "FilaDeImpressao.hpp"
#include <iostream>

FilaDeImpressao::FilaDeImpressao() : inicio(nullptr) {}

FilaDeImpressao::~FilaDeImpressao() {
    while (inicio) {
        Node* temp = inicio;
        inicio = inicio->next;
        delete temp;
    }
}

void FilaDeImpressao::adicionarDocumento(const Documentos& doc) {
    Node* novoDocumento = new Node(doc);
    
    if (!inicio || doc.getPrioridadeNivel() < inicio->documento.getPrioridadeNivel()) {
        novoDocumento->next = inicio;
        inicio = novoDocumento;
    } else {
        Node* atual = inicio;
        while (atual->next && doc.getPrioridadeNivel() >= atual->next->documento.getPrioridadeNivel()) {
            atual = atual->next;
        }
        novoDocumento->next = atual->next;
        atual->next = novoDocumento;
    }
}

Documentos FilaDeImpressao::consultarDocumento(int id) const {
    Node* atual = inicio;
    while (atual) {
        if (atual->documento.getId_documentos() == id) {
            return atual->documento;
        }
        atual = atual->next;
    }
    
    return Documentos(-1, "", 0, 0);
}

void FilaDeImpressao::listarDocumentos() const {
   if(!(estaVazia())){
    Node* atual = inicio;
    std::cout << "Documentos na fila de impressão:\n";
    while (atual) {
        std::cout << "ID: " << atual->documento.getId_documentos() << "\n";
        std::cout << "Nome do arquivo: " << atual->documento.getNomeDocumento() << "\n";
        std::cout << "Quantidade de páginas: " << atual->documento.getQuantidadePaginas() << "\n";
        std::cout << "Prioridade: " << atual->documento.getPrioridadeNivel() << "\n";
        std::cout << "-------------------------\n";
        atual = atual->next;
    }
   }else{
    std::cout<<"Nenhum item na fila\n";
   }
}

void FilaDeImpressao::atualizarDocumento(const Documentos& novoDocumento) {
    Node* atual = inicio;
    Node* anterior = nullptr;

    while (atual) {
        if (atual->documento.getId_documentos() == novoDocumento.getId_documentos()) {
            break;
        }
        anterior = atual;
        atual = atual->next;
    }

    if (!atual) {
        return;
    }

    if (anterior) {
      
        anterior->next = atual->next;
    } else {
        
        inicio = atual->next;
    }

   
    adicionarDocumento(novoDocumento);
}



bool FilaDeImpressao::removerDocumento(int id) {
    if (!inicio) {
        return false; 
    }

    if (inicio->documento.getId_documentos() == id) {
        Node* temp = inicio;
        inicio = inicio->next;
        delete temp;
        return true;
    }

    Node* atual = inicio;
    while (atual->next) {
        if (atual->next->documento.getId_documentos() == id) {
            Node* temp = atual->next;
            atual->next = temp->next;
            delete temp;
            return true;
        }
        atual = atual->next;
    }

    return false; 
}

bool FilaDeImpressao::estaVazia() const {
    return inicio == nullptr;
}
