// LinkedListEx.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main(){

    cout << "Linked List Example" << endl;

    LinkedList < double > nums;
    nums.insert(10.0);
    nums.insert(100.0);
    nums.insert(1.0);

    double aNum;
    if (nums.first(aNum))
    {
        cout << aNum << endl;
        while (nums.next(aNum))
        {
            cout << aNum << endl;
        }
        cout << endl;
    }
    cout << "The size of the list is " << nums.size() << endl;
    if (nums.isEmpty())
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        cout << "The list is NOT empty" << endl;
    }

    return 0;
}

