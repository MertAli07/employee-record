#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

Employee::Employee() {}

Employee::Employee(int number, int type, string name, string surname, string title, string salaryCo, string birth, string appointment, int service = 0)
{
    this->number = number;
    this->type = type;
    this->name = name;
    this->surname = surname;
    this->title = title;
    this->salaryCo = salaryCo;
    this->birth.setDay(stoi(birth.substr(0,2)));
    this->birth.setMonth(stoi(birth.substr(3,2)));
    this->birth.setYear(stoi(birth.substr(6,4)));
    this->appointment.setDay(stoi(appointment.substr(0,2)));
    this->appointment.setMonth(stoi(appointment.substr(3,2)));
    this->appointment.setYear(stoi(appointment.substr(6,4)));
    this->service = service;
}

int Employee::getNumber() const {return this->number;}
int Employee::getType() {return this->type;}
string Employee::getName() {return this->name;}
string Employee::getSurname() {return this->surname;}
string Employee::getTitle() {return this->title;}
string Employee::getSalaryCo() {return this->salaryCo;}

Date Employee::getBirth()
{return this->birth;}

Date Employee::getAppointment() const
{return this->appointment;}

int Employee::getService() {return this->service;}

void Employee::setNumber(int number) { this->number = number;}
void Employee::setType(int type) { this->type = type;}
void Employee::setName(string name) { this->name = name;}
void Employee::setSurname(string surname) { this->surname = surname;}
void Employee::setTitle(string title) { this->title = title;}
void Employee::setSalaryCo(string salaryCo) { this->salaryCo = salaryCo;}

void Employee::setBirth(string birth)
{
    this->birth.setDay(stoi(birth.substr(0,2)));
    this->birth.setMonth(stoi(birth.substr(3,2)));
    this->birth.setYear(stoi(birth.substr(6,4)));
}
void Employee::setAppointment(string appointment)
{
    this->appointment.setDay(stoi(appointment.substr(0,2)));
    this->appointment.setMonth(stoi(appointment.substr(3,2)));
    this->appointment.setYear(stoi(appointment.substr(6,4)));
}

void Employee::setService(int service) { this->service = service;}

ostream& operator<< (ostream& out,const Employee& e)
{
    out << "Number: " << e.number << endl
    << "Type: " << e.type << endl
    << "Name: " << e.name << endl
    << "Surname: " << e.surname << endl
    << "Title: " << e.title << endl
    << "Salary Coefficient: " << e.salaryCo << endl
    << "Birth: " << e.birth << endl
    << "Date of appointment: " << e.appointment << endl
    << "Length of service:" << e.service << endl;
    return out;
}

bool operator < (const Employee &e1,const Employee &e2)
{
    return e1.getNumber() < e2.getNumber();
}

bool operator > (const Employee &e1, const Employee &e2)
{
    return e1.getNumber() > e2.getNumber();
}