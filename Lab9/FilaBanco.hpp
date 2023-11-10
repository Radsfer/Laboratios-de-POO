#ifndef __FILABANCO_H__
#define __FILABANCO_H__
#include "Fila.hpp"
#include "Node.hpp"
#include "ClienteBanco.hpp"
#include <iostream>

class FilaBanco : public Fila<ClienteBanco> {
private:
    Node<ClienteBanco> *front;
    Node<ClienteBanco> *rear;

public:
    FilaBanco();
    ~FilaBanco();
    void enqueue(ClienteBanco &objt) override;
    void enqueuePriority(bool prioritary, ClienteBanco &objt) override;
    ClienteBanco dequeue() override;
    bool isEmpty() const override;
    void printQueue() const override;
    int sizeQueue() const override;
};

#endif // __FILABANCO_H__