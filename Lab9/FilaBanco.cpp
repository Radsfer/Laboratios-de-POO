#include "FilaBanco.hpp"
#include <iostream>


FilaBanco::FilaBanco() :front(nullptr), rear(nullptr){}


FilaBanco::~FilaBanco()
{
    while (front)
    {
        Node<ClienteBanco> *aux = front;
        front = front->next;
        delete aux;
    }
    rear = nullptr;
}


void FilaBanco::enqueue(ClienteBanco &objt)
{
    Node<ClienteBanco> *newObjt = new Node<ClienteBanco>(objt);
    int size = sizeQueue();
    if (rear == nullptr)
    {
        front = newObjt;
        rear = newObjt;
    }
    else
    {
        rear->next = newObjt;
        rear = newObjt;
    }
    std::cout << "\nPessoas a frente: " << size << std::endl;
    std::cout << "\nNome: " << rear->data.getNome()
              << "\nCPF: " << rear->data.getCpf()
              << "\nConta: " << rear->data.getNumeroConta()
              << "\nAgencia: " << rear->data.getAgencia() << std::endl;
}


void FilaBanco::enqueuePriority(bool prioritary, ClienteBanco &objt)
{
    Node<ClienteBanco> *newObjt = new Node<ClienteBanco>(objt);
    if (rear == nullptr)
    {
        front = newObjt;
        rear = newObjt;
    }
    else
    {
        if (prioritary)
        {
            newObjt->next = front;
            front = newObjt;
        }
        else
        {
            rear->next = newObjt;
            rear = newObjt;
        }
    }

    std::cout << "\nNome: " << front->data.getNome()
              << "\nCPF: " << front->data.getCpf()
              << "\nConta: " << front->data.getNumeroConta()
              << "\nAgencia: " << front->data.getAgencia() << std::endl;
}


ClienteBanco FilaBanco::dequeue()
{
    if (isEmpty())
    {
        ClienteBanco objtDefault;
        return objtDefault;
    }
    else
    {
        Node<ClienteBanco> *aux = front;
        ClienteBanco objtRemove = front->data;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete aux;
        return objtRemove;
    }
}


bool FilaBanco::isEmpty() const
{
    return front == nullptr;
}


void FilaBanco::printQueue() const
{
    if (!isEmpty())
    {
        Node<ClienteBanco> *current = front;
        while (current)
        {
            std::cout << "\nNome: " << current->data.getNome()
                      << "\nCPF: " << current->data.getCpf()
                      << "\nConta: " << current->data.getNumeroConta()
                      << "\nAgencia: " << current->data.getAgencia() << std::endl;
            current = current->next;
        }
    }
    else
    {
        std::cout << "Fila vazia." << std::endl;
    }
}


int FilaBanco::sizeQueue() const
{
    int count = 0;
    Node<ClienteBanco> *current = front;
    while (current)
    {
        count++;
        current = current->next;
    }
    return count;
}

