#include "LinkedList.h"
#include <iostream>
#include <iomanip>

using namespace std;

LinkedList::LinkedList()
{
    first = 0;
}

LinkedList::~LinkedList()
{
    Node* temp = first;

    while (temp != 0)
    {
        Node* deleted = temp;
        temp = temp->Next;
        delete deleted;
    }
}

void LinkedList::Add(int data)
{
    Node* added = new Node(data);

    //Eğer listede hiç eleman yoksa bu bloğa girilir ve eklenen eleman bu listenin ilk elemanı olur
    if(first == 0)
    {
        first = added;
    }
    else
    {
        Node* temp = first;

        //Bu döngüde listenin sonuna kadar gidilir ve döngünün hemen ardından verilen data ile oluşturulan düğüm listeye eklenir
        while (temp->Next != 0)
        {
            temp = temp->Next;
        }

        temp->Next = added;
    }
}

void LinkedList::Print()
{
    cout << setw(10) << "Address" << setw(10) << "Data" << setw(15) << "Next" << endl;
    cout << "---------------------------------------------" << endl;

    Node* temp = first;
    while (temp != 0)
    {
        cout << setw(10) << temp << setw(10) << temp->Data << setw(15) << temp->Next << endl;
        temp = temp->Next;
    }
}
