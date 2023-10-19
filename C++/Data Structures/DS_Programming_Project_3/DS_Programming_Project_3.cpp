#include <iostream>
#include <string>
#include "WordCombo.h"
#include "WordFinder.h"

using namespace std;

int main()
{
    cout << "Word Finder" << endl;

    //create a word finder
    WordFinder finder("C:/Users/braph/Desktop/Portfolio/CS2_files/bigDictionary.txt");

    //see which words can be made from "carton"    
    WordCombo results;
    if (finder.makeWordsFromWord("carton", results))
    {
        //print the results using the provided WordCombo class
        cout << results.toString() << endl;
    }
    //clear the results to reuse the word combo
    results.clear();

    //try another string
    if (finder.makeWordsFromWord("Cart On!", results))
    {
        //print the results using the provided WordCombo class
        cout << results.toString() << endl;
    }
    //clear the results to reuse the word combo
    results.clear();

    finder.replace('5', 's');
    finder.replace('3', 'e');

    //try a long string
    if (finder.makeWordsFromWord("m355y", results))
    {
        cout << results.toString() << endl;
    }
    results.clear();

    //create a date and use its hex value to see if it can make some words
    //DateFromEpoch aDate(202238670); //Sat May 29 12:24:30 1976

   // finder.replace('5', 's'); //replace all 5's with an 's'
    //finder.replace('0', 'o'); //replace all 0's with an 'o'

    /*if (finder.makeWordsFromWord(aDate.getHexValue(), results))
    {
        cout << results.toString() << endl;
    }
    */
    return 0;
}