#ifndef __FILA_H__
#define __FILA_H__
template <typename T>
class Fila{
    protected:
    struct Node{
        T object;
        Node* next;
        Node(const T& objt): object(objt), next(nullptr){};
    };
    Node* front;
    Node* rear;
    public:
    Fila();
    virtual ~Fila();    
    bool isEmpty();
    virtual void enqueue (T& objt);
    virtual void enqueuePriority(bool prioritary,T& objt);
    virtual T dequeue();
    T printQueue();
    int sizeQueue();
};
#endif // __FILA_H__