#ifndef __PILHAPROVAS_H__
#define __PILHAPROVAS_H__

#include "Pilha.hpp"
#include "Node.hpp"
#include "Prova.hpp"

class PilhaProvas : public Pilha<Prova>
{
private:
    Node<Prova> *topo;

public:
    PilhaProvas();
    ~PilhaProvas();

    bool isEmpty() const override;
    void push(const Prova &prova) override;
    Prova pop() override;
    Prova top() const override;
    int size() const override;
    void print() const override;
};

#endif // __PILHAPROVAS_H__
