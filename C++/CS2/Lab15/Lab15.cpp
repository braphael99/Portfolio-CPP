// Lab15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

int main()
{
    //birth names
    Person p1("Mark", "Mahoney");
    Person p2("Laura", "Cooper");
    //after marriage
    p2.updateLastName("Mahoney");

    cout << "Current Names:" << endl;
    cout << p1.getLast() << ", " << p1.getFirst() << endl; //Mahoney, Mark
    cout << p2.getLast() << ", " << p2.getFirst() << endl; //Mahoney, Laura
    cout << endl;

    cout << "Names at birth:" << endl;
    cout << p1.getOriginalLast() << ", " << p1.getFirst() << endl; //Mahoney, Mark
    cout << p2.getOriginalLast() << ", " << p2.getFirst() << endl; //Cooper, Laura
    cout << endl;

    return 0;
}