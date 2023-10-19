// DS_Programming_Project_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Trie.h"
#include "BoggleBoard.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    
    BoggleBoard myBoard("C:/Users/braph/Desktop/Portfolio/C++/Data Structures/bigDictionary.txt");

    myBoard.rollDice();
    myBoard.printBoard();
    myBoard.solve();

    myBoard.printWords();

}

