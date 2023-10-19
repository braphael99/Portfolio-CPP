// Lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Dictionary.h"

using namespace std;

int main()
{
    cout << "Welcome to the SpellCheck program!" << endl;

    //create a dictionary object from a single cleansed, sorted file
    Dictionary d("C:/Users/braph/Desktop/Portfolio/CS2_files/bigDictionary.txt");

    //add some new words to the dictionary
    d.addWordToDictionary("Momala");
    d.addWordToDictionary("obnoxion");

    //spellcheck a file
    d.spellCheck("C:/Users/braph/Desktop/Portfolio/CS2_files/testdoc.txt");

    return 0;
}
