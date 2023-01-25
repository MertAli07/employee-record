#ifndef ASSIGNMENT2_TEMPORARYEMPLOYEE_H
#define ASSIGNMENT2_TEMPORARYEMPLOYEE_H

#include "Employee.h"
class TemporaryEmployee: public Employee{

    using Employee::Employee;
public:
    int next;

    TemporaryEmployee();
};
#endif
