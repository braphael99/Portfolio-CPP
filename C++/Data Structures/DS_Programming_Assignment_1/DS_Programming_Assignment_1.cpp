// DS_Programming_Assignment_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "StringBuilder.h"

using namespace std;

int main()
{
    StringBuilder builder1;
    builder1.append("Alan ");
    builder1.append("Mathison ");
    builder1.append("Turing");
    string* p_name1 = builder1.getString(); //"Alan Mathison Turing"
    cout << "Name: " << *p_name1 << endl;
    delete p_name1;

    StringBuilder builder2;
    builder2.append("J. ");
    builder2.append("Robert ");
    builder2.append("Oppenheimer");
    string* p_name2 = builder2.getString(); //"J. Robert Oppenheimer"
    cout << "Name: " << *p_name2 << endl;
    delete p_name2;

    string nameParts[] = { "Alan ", "Mathison ", "Turing" };
    StringBuilder builder3;
    builder3.appendAll(nameParts, 3);
    string* p_name3 = builder3.getString(); //"Alan Mathison Turing"
    cout << "Name: " << *p_name3 << endl;
    delete p_name3;

    StringBuilder builder4;
    builder4.append("abc");
    builder4.append("a");
    builder4.append("b");
    builder4.append("c");

    //builder4.removeAll("b"); //"acac"
    builder4.removeAll("bc"); //"aa"
    //builder4.removeAll("abc"); //""
    //builder4.removeAll("bca"); //"abc"
    string* p_letters = builder4.getString();
    cout << "Letters: " << *p_letters << endl;
    delete p_letters;

    //now add some more 
    builder4.append("x");
    builder4.append("y");
    builder4.append("z");
    builder4.append("xyz");

    p_letters = builder4.getString();
    cout << "Letters: " << *p_letters << endl;
    delete p_letters;
}

