#ifndef ASSIGNMENT2_EMPLOYEE_H
#define ASSIGNMENT2_EMPLOYEE_H

#include <string>
#include "Date.h"
using namespace std;
class Employee {
private:
    int number;
    int type;
    string name;
    string surname;
    string title;
    string salaryCo;
    Date birth;
    Date appointment;
    int service;
public:
    Employee(int number, int type, string name, string surname, string title, string salaryCo, string birth, string appointment, int service);

    Employee();

    //Getters
    int getNumber() const;
    int getType();
    string getName();
    string getSurname();
    string getTitle();
    string getSalaryCo();
    Date getBirth();
    Date getAppointment() const;
    int getService();
    //Setters
    void setNumber(int number);
    void setType(int type);
    void setName(string name);
    void setSurname(string surname);
    void setTitle(string title);
    void setSalaryCo(string salaryCo);
    void setBirth(string birth);
    void setAppointment(string appointment);
    void setService(int service);

    friend ostream& operator << (ostream& out,const Employee& e);

    friend bool operator < (const Employee &e1,const Employee &e2);

    friend bool operator > (const Employee &e1,const Employee &e2);

};
#endif
