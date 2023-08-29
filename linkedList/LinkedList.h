#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include "Node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void Add(int data);
    void Print();

private:
    Node* first;
};

#endif //LINKEDLIST_LINKEDLIST_H
