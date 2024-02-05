#include "Date.h"

#include <cmath>
#include <iostream>
using namespace std;

Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{
}

Date::Date() : day(1), month(1), year(1970)
{
}

void Date::Print()
{
    cout << day << "." << month << "." << year << endl;
}

void Date::AddDay()
{
    int monthmax = 28 + (month + abs(month / 8) / 2 + 2 / month + 2 * (abs(1 / month)));
    if (month == 2)
    {
        if (year % 400 == 0 and year % 100 != 0 and year % 4 == 0)
        {
            monthmax = 29;
        }
    }

    day++;
    if (day > monthmax)
    {
        month++;
        day = 1;
    }
    if (month == 13)
    {
        month = 1;
        year++;
    }
}
