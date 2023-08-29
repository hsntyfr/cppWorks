#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H
class Node
{
public:
    Node(int data);
    ~Node();

    int Data;
    Node* Next;
};


#endif //LINKEDLIST_NODE_H
