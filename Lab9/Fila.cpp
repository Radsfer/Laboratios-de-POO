#include "Fila.hpp"

template <typename T>
bool Fila<T>::isEmpty()
{
    return front == nullptr;
}

template <typename T>
Fila<T>::Fila() : front(nullptr), rear(nullptr) {}

template <typename T>
Fila<T>::~Fila()
{
    while (front)
    {
        Node *aux = front;
        front = front->next;
        delete aux;
    }
    rear = nullptr;
}

template <typename T>
void Fila<T>::enqueue(T &objt)
{
    Node *newObjt = new Node(objt);

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
}

template<typename T>
void Fila<T>::enqueuePriority(bool prioritary,T& objt)
{
    Node* newObjt = new Node(objt); 
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
}

template <typename T>
T Fila<T>::dequeue()
{
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        Node *aux = front;
        T objtRemove = front->object;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete aux;
        return objtRemove;
    }
}

template <typename T>
T Fila<T>::printQueue()
{
    if (!(isEmpty()))
    {
        Node *aux = front;
        while (front)
        {
            aux->object;
            return aux;
            aux = aux->next;
        }
    }
    else
    {
        return nullptr;
    }
}

template <typename T>
int Fila<T>::sizeQueue()
{
    int aux = 0;
    if (!(isEmpty()))
    {
        Node *temp;
        while (front)
        {
            temp = front;
            front = front->next;
            if (front != nullptr)
            {
                aux++;
            }
        }
        return aux;
    }
    else
    {
        return aux;
    }
}
