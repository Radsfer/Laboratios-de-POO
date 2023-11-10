#ifndef __PILHA_H__
#define __PILHA_H__
#pragma once

template <typename T>
class Pilha
{
public:
    virtual bool isEmpty() const = 0;
    virtual void push(const T &elemento) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual int size() const = 0;
    virtual void print() const = 0;
    virtual ~Pilha() {}
};

#endif // __PILHA_H__