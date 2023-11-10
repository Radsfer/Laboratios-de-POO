#include "PilhaProvas.hpp"
#include <iostream>
#include <iomanip>

PilhaProvas::PilhaProvas() : topo(nullptr) {}

PilhaProvas::~PilhaProvas()
{
    while (topo)
    {
        Node<Prova> *temp = topo;
        topo = topo->next;
        delete temp;
    }
}

bool PilhaProvas::isEmpty() const
{
    return (topo == nullptr);
}

void PilhaProvas::push(const Prova &prova)
{
    Node<Prova> *novoNo = new Node<Prova>(prova);
    novoNo->next = topo;
    topo = novoNo;
    std::cout
        << "\nNumero de provas na pilha: " << size()
        << "\nCódigo da prova: " << novoNo->data.getCodigoProva()
        << "\nDisciplina: " << novoNo->data.getDisciplina()
        << "\nAluno: " << novoNo->data.getAluno().getNome()
        << "\nNota: " << std::fixed << std::setprecision(2) << novoNo->data.getNota()
        << std::endl;
}

Prova PilhaProvas::pop()
{
    if (isEmpty())
    {
        Prova objtDefault;
        return objtDefault;
    }

    Prova provaDesempilhada = topo->data;
    Node<Prova> *temp = topo;
    topo = topo->next;
    delete temp;

    return provaDesempilhada;
}

Prova PilhaProvas::top() const
{
    if (isEmpty())
    {
        Prova objtDefault;
        return objtDefault;
    }

    return topo->data;
}

int PilhaProvas::size() const
{
    int count = 0;
    Node<Prova> *temp = topo;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void PilhaProvas::print() const
{
    Node<Prova> *temp = topo;

    std::cout << "Conteúdo da Pilha de Provas:" << std::endl;

    while (temp != nullptr)
    {
        std::cout << "\nCódigo da prova: " << temp->data.getCodigoProva()
                  << "\nDisciplina: " << temp->data.getDisciplina()
                  << "\nAluno: " << temp->data.getAluno().getNome()
                  << "\nNota: " << std::fixed << std::setprecision(2) << temp->data.getNota()
                  << std::endl;

        temp = temp->next;
    }
}
