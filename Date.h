#ifndef ASSIGNMENT2_DATE_H
#define ASSIGNMENT2_DATE_H

#include <string>
using namespace std;
class Date{
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int d, int m, int y);
    Date(string emp_date);
    //Getters
    int getDay();
    int getMonth();
    int getYear();
    //Setters
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    friend bool operator < (const Date &d1, const Date &d2);

    friend bool operator > (const Date &d1, const Date &d2);

    friend bool operator == (const Date &d1, const Date &d2);

    friend ostream& operator << (ostream& out,const Date& d);
};
#endif
