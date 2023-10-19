// Lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool isLeapYear(int);

int main()
{
    int testYear = 1900;

    if (isLeapYear(testYear))
    {
        cout << testYear << " is a leapyear" << endl;
    }
    else
    {
        cout << testYear << " is NOT a leapyear" << endl;
    }
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