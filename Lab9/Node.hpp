#ifndef __NODE_H__
#define __NODE_H__
template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T _data) : data(_data), next(nullptr) {}
};
#endif // __NODE_H__