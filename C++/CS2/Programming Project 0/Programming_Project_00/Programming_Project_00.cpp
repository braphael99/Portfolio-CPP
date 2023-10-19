//Blake Raphael
//CSC 1820 Section 2
//Programming_Project_00

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isLeapYear(int year);
int getDaysInMonth(int month, int year);
int getDaysUpTo(int month, int day, int year);
int getDaysLeftInYear(int month, int day, int year);
void parseDate(string dateString, int& month, int& day, int& year);
int differenceBetweenDates(string dateOne, string dateTwo);
string addDays(string dateString, int daysToAdd);

int main()
{
   int diffDays = differenceBetweenDates("3/19/1973", "1/20/2021");
   cout << "Difference: " << diffDays << "\n";

   int diffDaysTwo = differenceBetweenDates("9/20/2001", "6/16/2004");
   cout << "Difference: " << diffDaysTwo << "\n";
   
   string newDate = addDays("9/20/2001", 1000);
   cout << "New date: " << newDate << "\n";

   string newDateTwo = addDays("1/20/2021", 500);
   cout << "New date: " << newDateTwo << "\n";
    
    return 0;
}

bool isLeapYear(int year)
{

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else{
            return true;
        }
    }
    else {
        return false;
    }
    return false;
}

int getDaysInMonth(int month, int year) {

    vector < int > monthDays = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeapYear(year) && month == 2) {
        return 29;
    }
    else {
        return monthDays[month];
    }
}

int getDaysUpTo(int month, int day, int year) {


    int sumDays = 0;

    for (int i = 1; i < month; i++) {

        sumDays += getDaysInMonth(i, year);

    }

    sumDays += day;
    return sumDays;
}

int getDaysLeftInYear(int month, int day, int year) {

    int daysLeft = 0;

    daysLeft += getDaysUpTo(month, day, year);
    if (isLeapYear(year)) {
        daysLeft = 366 - daysLeft + 1;
    }
    else {
       daysLeft = 365 - daysLeft + 1;
    }
    return daysLeft;
}

void parseDate(string dateString, int& month, int& day, int& year) {

    size_t pos = dateString.find("/");
    string monthString = dateString.substr(0, pos);
    month = stoi(monthString);
    dateString.erase(0, pos + 1);

    pos = dateString.find("/");
    string dayString = dateString.substr(0, pos);
    day = stoi(dayString);
    dateString.erase(0, pos + 1);

    year = stoi(dateString);
}

 int differenceBetweenDates(string dateOne, string dateTwo) {

    int dayOne = 0;
    int dayTwo = 0;
    int monthOne = 0;
    int monthTwo = 0;
    int yearOne = 0;
    int yearTwo = 0;
    int currentYear = 0;
    int totalDays = 0;

    parseDate(dateOne, monthOne, dayOne, yearOne);
    parseDate(dateTwo, monthTwo, dayTwo, yearTwo);

    currentYear = yearOne;

    totalDays += getDaysLeftInYear(monthOne, dayOne, yearOne);

    currentYear++;

    for (int i = 0; i < yearTwo - yearOne - 1; i++) {

        if (isLeapYear(currentYear)) {
            totalDays += 366;
        }
        else {
            totalDays += 365;
        }
        currentYear++;
    }

    totalDays += getDaysUpTo(monthTwo, dayTwo, yearTwo);

    return totalDays;
} 

string addDays(string dateString, int daysToAdd) {

    int month = 0;
    int day = 0;
    int year = 0;
    int remainingDays = daysToAdd;

    parseDate(dateString, month, day, year);

    while (remainingDays >= 365) {
        if (isLeapYear(year)) {
            
            remainingDays -= 366;
            year++;
        }
        else {
            
            remainingDays -= 365;
            year++;
        }

    }
    while (remainingDays >= getDaysInMonth(month, year)) {
        remainingDays -= getDaysInMonth(month, year);
        month++;

        if (month == 13) {
            month = 1;
            year++;
        }
    }

    day += remainingDays;

    if (day > getDaysInMonth(month, year)) {
        day -= getDaysInMonth(month, year);
        month++;
        
    }

    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}