
#include <iostream>
#include <vector>
#include <algorithm>
#include "DoubleDynamicLinkedList.h"
#include "CircularArrayLinkedList.h"
#include <string>
using namespace std;

//method: 6
void printAllByNum(CircularArrayLinkedList* cList, DoubleDynamicLinkedList* dList)
{
    vector<Employee> v;
    for(int i = 0; i<cList->avail; i++)
    {
        v.push_back(cList->listArray[i]);
    }
    PermanentEmployee* last = dList->head;
    while(last != NULL)
    {
        v.push_back(*last);
        last = last->next;
    }
    sort(v.begin(), v.end());
    for(Employee e: v)
    {
        cout << e << endl;
    }
}

bool comparator(const Employee& e1,const Employee& e2) {
    return e1.getAppointment() < e2.getAppointment();
}

//method: 7
void printAllByDate(CircularArrayLinkedList* cList, DoubleDynamicLinkedList* dList)
{
    vector<Employee> v;
    for(int i = 0; i<cList->avail; i++)
    {
        v.push_back(cList->listArray[i]);
    }
    PermanentEmployee* last = dList->head;
    while(last != NULL)
    {
        v.push_back(*last);
        last = last->next;
    }
    sort(v.begin(), v.end(), &comparator);
    for(Employee e: v)
    {
        cout << e << endl;
    }
}

//method: 8
void printAllAfterDate(CircularArrayLinkedList* cList, DoubleDynamicLinkedList* dList, string emp_date)
{
    vector<Employee> v;
    for(int i = 0; i<cList->avail; i++)
    {
        v.push_back(cList->listArray[i]);
    }
    PermanentEmployee* last = dList->head;
    while(last != NULL)
    {
        v.push_back(*last);
        last = last->next;
    }
    sort(v.begin(), v.end(), &comparator);
    reverse(v.begin(), v.end());
    Date d(emp_date);

    for(Employee e: v)
    {
        if(e.getAppointment() > d)
        {
            cout << e << endl;
        }
    }
}

//method:9
void printAllInYear(CircularArrayLinkedList* cList, DoubleDynamicLinkedList* dList, string emp_year)
{
    vector<Employee> v;
    for(int i = 0; i<cList->avail; i++)
    {
        v.push_back(cList->listArray[i]);
    }
    PermanentEmployee* last = dList->head;
    while(last != NULL)
    {
        v.push_back(*last);
        last = last->next;
    }
    sort(v.begin(), v.end(), &comparator);
    Date d;
    d.setYear(stoi(emp_year));

    for(Employee e: v)
    {
        if(d.getYear() == e.getAppointment().getYear())
        {
            cout << e << endl;
        }
    }
}

//method:10
void printAllBeforeDate(CircularArrayLinkedList* cList, DoubleDynamicLinkedList* dList, string emp_date)
{
    vector<Employee> v;
    for(int i = 0; i<cList->avail; i++)
    {
        v.push_back(cList->listArray[i]);
    }
    PermanentEmployee* last = dList->head;
    while(last != NULL)
    {
        v.push_back(*last);
        last = last->next;
    }
    sort(v.begin(), v.end());
    Date d(emp_date);
    for(Employee e: v)
    {
        if(e.getBirth() < d)
        {
            cout << e << endl;
        }
    }
}

//method:11
void printAllInMonth(CircularArrayLinkedList* cList, DoubleDynamicLinkedList* dList, string emp_month)
{
    vector<Employee> v;
    for(int i = 0; i<cList->avail; i++)
    {
        v.push_back(cList->listArray[i]);
    }
    PermanentEmployee* last = dList->head;
    while(last != NULL)
    {
        v.push_back(*last);
        last = last->next;
    }
    sort(v.begin(), v.end());
    Date d;
    d.setMonth(stoi(emp_month));
    for(Employee e: v)
    {
        if(e.getBirth().getMonth() == d.getMonth())
        {
            cout << e << endl;
        }
    }
}

//method:12
void printTitle(CircularArrayLinkedList* cList, DoubleDynamicLinkedList* dList, string emp_title)
{
    vector<Employee> v;
    for(int i = 0; i<cList->avail; i++)
    {
        v.push_back(cList->listArray[i]);
    }
    PermanentEmployee* last = dList->head;
    while(last != NULL)
    {
        v.push_back(*last);
        last = last->next;
    }
    sort(v.begin(), v.end(), &comparator);
    reverse(v.begin(), v.end());

    for(Employee e: v)
    {
        if(e.getTitle() == emp_title)
        {
            cout << e << endl;
            break;
        }
    }
}

int main() {
    DoubleDynamicLinkedList* dList = new DoubleDynamicLinkedList();
    CircularArrayLinkedList* cList = new CircularArrayLinkedList();
    while (true)
    {
        cout << "___ Employee Recording System ___" << endl;
        cout << "Please select for the following Menu Operation:" << endl;
        cout << "1) Appointment of a new employee" << endl;
        cout << "2) Appointment of a transferred employee" << endl;
        cout << "3) Updating the title and salary coefficient of an employee" << endl;
        cout << "4) Deletion of an employee" << endl;
        cout << "5) Listing the information of an employee" << endl;
        cout << "6) Listing employees ordered by employee number" << endl;
        cout << "7) Listing employees ordered by appointment date" << endl;
        cout << "8) Listing employees appointed after a certain date" << endl;
        cout << "9) Listing employees assigned in a given year" << endl;
        cout << "10) Listing employees born before a certain date" << endl;
        cout << "11) Listing employees born in a particular month" << endl;
        cout << "12) Listing the information of the last assigned employee with a given title" << endl;
        string input;
        cout << "Enter operation number:";
        cin >> input;
        if(input == "1")
        {
            int emp_num;
            cout << "Enter employee number:";
            cin >> emp_num;
            if(cList->contains(emp_num) || dList->contains(emp_num))
            {
                cout << "This employee already exists!" << endl;
                continue;
            }
            int emp_type;
            cout << "Enter employee type:";
            cin >> emp_type;

            string emp_name;
            cout << "Enter employee name:";
            cin >> emp_name;

            string emp_surname;
            cout << "Enter employee surname:";
            cin >> emp_surname;

            string emp_title;
            cout << endl;
            cout << "Enter title:" << endl;
            cin >> emp_title;

            string emp_salaryco;
            cout << "Enter employee salary coefficient:";
            cin >> emp_salaryco;

            string emp_birth;
            cout << "Enter employee date of birth:";
            cin >> emp_birth;

            string emp_appo;
            cout << "Enter employee date of appointment to the institution:";
            cin >> emp_appo;
            cout << endl;

            if(emp_type == 0)
            {
                TemporaryEmployee* t1 = new TemporaryEmployee(emp_num, emp_type, emp_name, emp_surname, emp_title, emp_salaryco, emp_birth, emp_appo, 0);
                cList->insert(t1);
            }
            else if(emp_type == 1)
            {
                PermanentEmployee* p1 = new PermanentEmployee(emp_num, emp_type, emp_name, emp_surname, emp_title, emp_salaryco, emp_birth, emp_appo, 0);
                dList->insertBack(p1);
            }
            else
            {
                cout << "Invalid employee type. Try again." << endl;
            }
        }
        else if(input == "2")
        {
            int emp_num;
            cout << "Enter employee number:";
            cin >> emp_num;
            if(cList->contains(emp_num) || dList->contains(emp_num))
            {
                cout << "This employee already exists!" << endl;
                continue;
            }
            int emp_type;
            cout << "Enter employee type:";
            cin >> emp_type;

            string emp_name;
            cout << "Enter employee name:";
            cin >> emp_name;

            string emp_surname;
            cout << "Enter employee surname:";
            cin >> emp_surname;

            string emp_title;
            cout << endl;
            cout << "Enter title:";
            cin >> emp_title;

            string emp_salaryco;
            cout << "Enter employee salary coefficient:";
            cin >> emp_salaryco;

            string emp_birth;
            cout << "Enter employee date of birth:";
            cin >> emp_birth;

            string emp_appo;
            cout << endl;
            cout << "Enter employee date of appointment to the institution:";
            cin >> emp_appo;

            int emp_service;
            cout << endl;
            cout << "Enter length of service:";
            cin >> emp_service;
            cout << endl;

            if(emp_type == 0)
            {
                TemporaryEmployee* t1 = new TemporaryEmployee(emp_num, emp_type, emp_name, emp_surname, emp_title, emp_salaryco, emp_birth, emp_appo, emp_service);
                cList->insert(t1);
            }
            else if(emp_type == 1)
            {
                PermanentEmployee* p1 = new PermanentEmployee(emp_num, emp_type, emp_name, emp_surname, emp_title, emp_salaryco, emp_birth, emp_appo, emp_service);
                dList->insertBack(p1);
            }
            else
            {
                cout << "Invalid employee type. Try again." << endl;
            }
        }
        else if (input == "3")
        {
            int emp_num;
            cout << "Enter employee number:";
            cin >> emp_num;

            if(cList->contains(emp_num))
            {
                string emp_sal;
                cout << "Enter new salary coefficient:";
                cin >> emp_sal;

                string emp_title;
                cout << "Enter new title:";
                cin >> emp_title;

                cList->update(emp_num, emp_sal, emp_title);
            }
            else if(dList->contains(emp_num))
            {
                string emp_sal;
                cout << "Enter new salary coefficient:";
                cin >> emp_sal;

                string emp_title;
                cout << "Enter new title:";
                cin >> emp_title;

                dList->update(emp_num, emp_sal, emp_title);
            }
            else
            {
                cout << "This employee does not exist." << endl;
            }
        }
        else if(input == "4")
        {
            int emp_num;
            cout << "Enter employee number:";
            cin >> emp_num;

            if(cList->contains(emp_num))
            {
                cList->deletion(emp_num);
            }
            else if(dList->contains(emp_num))
            {
                dList->deletion(emp_num);
            }
            else
            {
                cout << "This employee does not exist." << endl;
            }
        }
        else if(input == "5")
        {
            int emp_num;
            cout << "Enter employee number:";
            cin >> emp_num;

            if(cList->contains(emp_num))
            {
                cList->info(emp_num);
            }
            else if(dList->contains(emp_num))
            {
                dList->info(emp_num);
            }
            else
            {
                cout << "This employee does not exist." << endl;
            }
        }
        else if(input == "6")
        {
            printAllByNum(cList, dList);
        }
        else if(input == "7")
        {
            printAllByDate(cList, dList);
        }
        else if(input == "8")
        {
            string emp_date;
            cout << "Enter date: ";
            cin >> emp_date;

            printAllAfterDate(cList, dList, emp_date);
        }
        else if(input == "9")
        {
            string emp_year;
            cout << "Enter year: ";
            cin >> emp_year;

            printAllInYear(cList, dList, emp_year);
        }
        else if(input == "10")
        {
            string emp_date;
            cout << "Enter date: ";
            cin >> emp_date;

            printAllBeforeDate(cList, dList, emp_date);
        }
        else if(input == "11")
        {
            string emp_month;
            cout << "Enter month: ";
            cin >> emp_month;

            printAllInMonth(cList, dList, emp_month);
        }
        else if(input == "12")
        {
            string emp_title;
            cout << "Enter title: ";
            cin >> emp_title;

            printTitle(cList, dList, emp_title);
        }
        else
        {
            cout << "Invalid operation number. Try again." << endl;
        }
    }
    return 0;
}
