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

void LinkedList::AddBack(int data)
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
    cout << endl;
}

void LinkedList::AddTop(int data)
{
    Node* added = new Node(data);

    if(first == 0)
    {
        first = added;
    }
    else
    {
        Node* temp = first;

        added->Next = first;
        first = added;
    }
}

void LinkedList::Insert(int index, int data)
{
    int counter = 0;
    Node* added = new Node(data);
    Node* iter = first;

    //Burada listenin tek elemanlı olup olmadığı kontrol ediliyor
    if(first == 0)
    {
        added = first;
    }
    else
    {
        if(index == 0)
        {
            AddTop(data);
        }
        //Burada listenin eleman sayısı bulunuyor indekse göre hareket etmek için lazım
        while(iter != 0)
        {
            counter++;
            iter = iter->Next;
        }

        //Listede tek eleman varsa direkt ekliyor index 0 ise başa ekleme fonksiyonu ile ekliyor
        if(counter == 1)
        {
            first->Next = added;
        }

        //Araya ekleme işlemi burada oluyor
        else if(index != 0)
        {
            iter = first;
            cout << "Counter: " << counter << endl;
            for(int i = 0; i < index - 1; i++)
            {
                iter = iter->Next;
            }
            added->Next = iter->Next->Next;
            iter->Next = added;
        }
    }
}

void LinkedList::RemoveIndex(int index)
{
    int counter = 0;
    Node* iter = first;
    Node* temp;

    while(iter != 0)
    {
        counter++;
        iter = iter->Next;
    }

    if(index == 0)
    {
        temp = first->Next;
        delete first;
        first = temp;
    }
    else
    {
        iter = first;

        for(int i = 0; i < index - 1; i++)
        {
            iter = iter->Next;
        }
        temp = iter->Next;
        iter->Next = iter->Next->Next;
        delete temp;
    }
}

void LinkedList::AddSort(int data)
{
    Node* added = new Node (data);
    Node* iter = first;


    if(first == 0)
    {
        first = added;
    }
    else
    {

       /*if(iter->Data >= data)
       {
           AddTop(data);
       }
       else
       {

       }*/

        while ()
        {
            
        }

    }
}




































































