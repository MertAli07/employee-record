#ifndef ASSIGNMENT2_PERMANENTEMPLOYEE_H
#define ASSIGNMENT2_PERMANENTEMPLOYEE_H

#include "Employee.h"
class PermanentEmployee: public Employee{

    using Employee::Employee;
public:
    PermanentEmployee* prev;
    PermanentEmployee* next;

    PermanentEmployee();

};
#endif
