#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    Person(string f, string l);
    ~Person();
    void updateLastName(string newLast);
    string getFirst();
    string getOriginalLast();
    string getLast();
private:
    string* p_first;
    string* p_last;
    string* p_updatedLast;
};

