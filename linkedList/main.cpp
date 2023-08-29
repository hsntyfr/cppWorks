#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main() {
    /*Node* n1;
    cout << n1 << endl << &n1 << endl;
    n1 = 0;
    cout << n1 << endl << &n1 << endl;
    Node* n2 = new Node(2);
    Node* n3 = new Node(2);
    n2->Next = n3;
    cout << n2->Next << endl << n2->Data << endl << &n2 << endl << n2 << endl << n3;
    delete n2;
    n2 = 0;*/

    LinkedList* l = new LinkedList();
    l->Add(10);
    l->Add(20);
    l->Add(30);
    l->Add(40);
    l->Add(50);
    l->Add(60);

    l->Print();

    delete l;

    return 0;
}
