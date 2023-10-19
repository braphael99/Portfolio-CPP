#include <iostream>
#include "WordCombo.h"

using namespace std;

WordCombo::WordCombo() {



}

void WordCombo::setOriginalWord(string word)
{
    originalWord = word;
}
//--
void WordCombo::addWords(const vector < string >& newCombo)
{
    words.push_back(newCombo);
}
//--
void WordCombo::clear()
{
    originalWord = "";
    words.clear();
}
//--
string WordCombo::toString()
{
    string retVal = "Original Word: " + originalWord + "\n";
    if(words.size() > 0)
    {
        retVal += "These whole words can be made: \n";
        for(vector < string > madeWords : words)
        {
            retVal += " - ";
            for(string word : madeWords)
            {
                retVal += word + " ";
            }
            retVal += "\n";
        }
    }
    else
    {
        retVal += "No words can be made from '" + originalWord + "'.\n";
    }
    
    return retVal;
}

