#ifndef ASSIGNMENT2_CIRCULARRAYLINKEDLIST_H
#define ASSIGNMENT2_CIRCULARRAYLINKEDLIST_H

#include "TemporaryEmployee.h"
class CircularArrayLinkedList {
public:
    TemporaryEmployee* listArray;
    int head;
    int avail;
    CircularArrayLinkedList();
    CircularArrayLinkedList(int size);
    ~CircularArrayLinkedList();

    //Adds the item to the end of the circular list
    void append(TemporaryEmployee* e);

    void printList();

    //Ckecks if array contains employee with given number
    bool contains(int num);

    //Insert employee to the circular array according to its number
    void insert(TemporaryEmployee* e);

    //Updates salary coefficient and title of an employee
    void update(int emp_num, string newSalCo, string newTitle);

    //Delete the employee
    void deletion(int emp_num);

    //Information of the employee
    void info(int emp_num);

};
#endif
