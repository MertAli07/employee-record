
#include "DoubleDynamicLinkedList.h"
#include <iostream>


DoubleDynamicLinkedList::DoubleDynamicLinkedList()
{
    this->head = NULL;
}

void DoubleDynamicLinkedList::insertFront(PermanentEmployee* e)
{
    e->next = head;
    e->prev = NULL;
    if(head != NULL)
    {
        head->prev = e;
    }
    head = e;
}

void DoubleDynamicLinkedList::insertBack(PermanentEmployee *e)
{
    PermanentEmployee* last = head;
    if (head == NULL)
    {
        e->prev = NULL;
        head = e;
        return;
    }
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = e;
    e->prev = last;
}

void DoubleDynamicLinkedList::printList()
{
    PermanentEmployee* last = head;
    while(last != NULL)
    {
        cout << last->getNumber() << " ";
        last = last->next;
    }
}

bool DoubleDynamicLinkedList::contains(int num)
{
    PermanentEmployee* last = head;
    while(last != NULL)
    {
        if(num == last->getNumber()) {return true;}
        last = last->next;
    }
    return false;
}

void DoubleDynamicLinkedList::update(int emp_num, string newSalCo, string newTitle)
{
    PermanentEmployee* last = head;
    while(last != NULL)
    {
        if(last->getNumber() == emp_num)
        {
            last->setSalaryCo(newSalCo);
            last->setTitle(newTitle);
            break;
        }
        last = last->next;
    }
}

void DoubleDynamicLinkedList::deletion(int emp_num)
{
    PermanentEmployee* del;
    PermanentEmployee* last = head;
    while(last != NULL)
    {
        if(last->getNumber() == emp_num)
        {
            del = last;
            break;
        }
        last = last->next;
    }
    if(head == del)
    {
        head = del->next;
    }
    if(del->next != NULL)
    {
        del->next->prev = del->prev;
    }
    if(del->prev != NULL)
    {
        del->prev->next = del->next;
    }
    free(del);
}

void DoubleDynamicLinkedList::info(int emp_num)
{
    PermanentEmployee* last = head;
    while(last != NULL)
    {
        if(last->getNumber() == emp_num)
        {
            cout << *last;
            break;
        }
        last = last->next;
    }
}

int DoubleDynamicLinkedList::length()
{
    int size = 0;
    PermanentEmployee* last = head;
    while (last != NULL)
    {
        size++;
        last = last->next;
    }
    return size;
}