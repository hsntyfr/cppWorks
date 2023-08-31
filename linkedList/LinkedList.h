#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include "Node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void AddBack(int data);
    void Print();
    void AddTop(int data);
    void Insert(int index, int data);
    void RemoveIndex(int index);
    void AddSort(int data);
private:
    Node* first;
};

#endif //LINKEDLIST_LINKEDLIST_H
