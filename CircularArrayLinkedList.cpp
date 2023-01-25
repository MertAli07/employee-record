
#include "CircularArrayLinkedList.h"
#include <iostream>
#include <string>
using namespace std;

CircularArrayLinkedList::CircularArrayLinkedList()
{
    this->listArray = new TemporaryEmployee[20];
    this->avail = 0;
    this->head = 0;
    for(int i = 0; i<19; i++)
    {
        listArray[i].next = i+1;
    }
    listArray[19].next = head;
}

CircularArrayLinkedList::CircularArrayLinkedList(int size)
{
    this->listArray = new TemporaryEmployee[size];
    this->avail = 0;
    this->head = 0;
    for(int i = 0; i<19; i++)
    {
        listArray[i].next = i+1;
    }
    listArray[19].next = head;
}

CircularArrayLinkedList::~CircularArrayLinkedList()
{
    delete[] listArray;
}

void CircularArrayLinkedList::append(TemporaryEmployee* e)
{
    if(this->avail == 20) //List is full
    {
        cout << "Cannot append, list is full!" << endl;
    }
    listArray[this->avail] = *e;
    this->avail++;
}

void CircularArrayLinkedList::printList()
{
    for(int i = 0; i < this->avail; i++)
    {
        cout << listArray[i].getNumber() << " ";
    }
}

bool CircularArrayLinkedList::contains(int num)
{
    for(int i = 0; i < this->avail; i++)
    {
        if(listArray[i].getNumber() == num) {return true;}
    }
    return false;
}

void CircularArrayLinkedList::insert(TemporaryEmployee *e)
{
    if(this->avail == 20) //List is full
    {
        cout << "Cannot insert, list is full!" << endl;
    }
    else if(this->avail == 0) //List is empty
    {
        this->append(e);
    }
    else
    {
        if(e->getNumber() < listArray[0].getNumber()) //Beginning of the list
        {
            for(int i = avail; i > 0; i--)
            {
                listArray[i] = listArray[i-1];
            }
            listArray[0] = *e;
            this->avail++;
        }
        else if(e->getNumber() > listArray[avail-1].getNumber()) //End of the list
        {
            listArray[avail] = *e;
            this->avail++;
        }
        else //An intermediate position
        {
            for(int i = 0; i < avail; i++)
            {
                if(listArray[i].getNumber() < e->getNumber() && e->getNumber() < listArray[i+1].getNumber())
                {
                    for(int j = avail; j > i; j--)
                    {
                        listArray[j] = listArray[j-1];
                    }
                    listArray[i+1] = *e;
                    this->avail++;
                }
            }
        }
    }
}

void CircularArrayLinkedList::update(int emp_num, string newSalCo, string newTitle)
{
    for(int i = 0; i < avail; i++)
    {
        if(this->listArray[i].getNumber() == emp_num)
        {
            this->listArray[i].setSalaryCo(newSalCo);
            this->listArray[i].setTitle(newTitle);
            break;
        }
    }
}

void CircularArrayLinkedList::deletion(int emp_num)
{
    for(int i = 0; i< avail ; i++)
    {
        if(this->listArray[i].getNumber() == emp_num)
        {
            for(int j = i; j < avail-1; j++)
            {
                this->listArray[j] = this->listArray[j+1];
            }
            this->avail--;
            break;
        }
    }
}

void CircularArrayLinkedList::info(int emp_num)
{
    for(int i = 0; i < avail; i++)
    {
        if(listArray[i].getNumber() == emp_num)
        {
            cout << listArray[i];
            break;
        }
    }
}
