#ifndef ASSIGNMENT2_DOUBLEDYNAMICLINKEDLIST_H
#define ASSIGNMENT2_DOUBLEDYNAMICLINKEDLIST_H

#include "PermanentEmployee.h"
class DoubleDynamicLinkedList {
public:
    PermanentEmployee* head;
    DoubleDynamicLinkedList();

    void insertFront(PermanentEmployee* e);
    void insertBack(PermanentEmployee* e);
    void printList();
    bool contains(int num);

    //Updates salary coefficient and title of an employee
    void update(int emp_num, string newSalCo, string newTitle);

    //Deletion of the employee
    void deletion(int emp_num);

    //Information of the employee
    void info(int emp_num);

    //returns the length
    int length();

};
#endif
