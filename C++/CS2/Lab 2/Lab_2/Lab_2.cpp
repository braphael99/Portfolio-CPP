// Lab_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

bool isLeapYear(int year);
int getDaysInMonth(int month, int year);
int getDaysUpTo(int month, int day, int year);
int getDaysLeftInYear(int month, int day, int year);

int main()
{
    int year = 2001;
    int day = 1;
    int month = 0;

    cout << "days in the month you sent: " << getDaysInMonth(month, year) << "\n";
    cout << "days passed that have led up to the date you sent: " << getDaysUpTo(month, day, year) << "\n";
    cout << "days left in the year from the date you sent: " << getDaysLeftInYear(month, day, year) << "\n";

}

bool isLeapYear(int year)
{

    if (year % 400 == 0) {

        return true;

        if (year % 100 == 0) {

            return false;

            if (year % 4 == 0) {
                return true;

            }
        }
    }

    return false;
}

int getDaysInMonth(int month, int year) {

    vector < int > monthDays = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeapYear(year) && month == 1) {
        return 29;
    }
    else {
        return monthDays[month];
    }

}

int getDaysUpTo(int month, int day, int year) {


    int sumDays = 0;

    for (int i = 0; i < month - 1; i++) {

        sumDays += getDaysInMonth(i, year);

    }

    sumDays += day;
    return sumDays;
}

int getDaysLeftInYear(int month, int day, int year) {

    int daysLeft = 0;

    daysLeft += getDaysUpTo(month, day, year);

    daysLeft = 365 - daysLeft;
    return daysLeft;

}