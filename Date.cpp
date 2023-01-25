#include "Date.h"
Date::Date() {};
Date::Date(int d, int m, int y)
{
    this->day = d;
    this->month = m;
    this->year = y;
}
Date::Date(string emp_date)
{
    this->day = stoi(emp_date.substr(0,2));
    this->month = stoi(emp_date.substr(3,2));
    this->year = stoi(emp_date.substr(6,4));
}

int Date::getDay() {return this->day;}
int Date::getMonth() {return this->month;}
int Date::getYear() {return this->year;}

void Date::setDay(int d) {this->day = d;}
void Date::setMonth(int m) {this->month = m;}
void Date::setYear(int y) {this->year = y;}

bool operator < (const Date &d1, const Date &d2)
{
    if(d1.year != d2.year) {return d1.year < d2.year;}
    else if((d1.year == d2.year) && (d1.month != d2.month))
    {
        return d1.month < d2.month;
    }
    else
    {
        return d1.day < d2.day;
    }
}

bool operator > (const Date &d1, const Date &d2)
{
    if(d1.year != d2.year) {return d1.year > d2.year;}
    else if((d1.year == d2.year) && (d1.month != d2.month))
    {
        return d1.month > d2.month;
    }
    else
    {
        return d1.day > d2.day;
    }
}

bool operator == (const Date &d1, const Date &d2)
{
    return (d1.year == d2.year) && (d1.month == d2.month) && (d1.day == d2.day);
}

ostream& operator << (ostream& out,const Date& e)
{
    out << to_string(e.day)+"-"+ to_string(e.month)+"-"+ to_string(e.year);
    return out;
}