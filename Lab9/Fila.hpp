#ifndef __FILA_H__
#define __FILA_H__
#include <iostream>
#pragma once

template <typename T>
class Fila
{
public:
    virtual bool isEmpty() const = 0;
    virtual void enqueue(T &objt) = 0;
    virtual T dequeue() = 0;
    virtual void printQueue() const = 0;
    virtual int sizeQueue() const = 0;
    virtual void enqueuePriority(bool prioritary, T &objt) = 0;
    virtual ~Fila() {}
};
#endif // __FILA_H__