#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int data)
{
    this->Data = data;
    this->Next = 0;
}
Node::~Node()
{
    cout << Data << " deleted" << endl;

}