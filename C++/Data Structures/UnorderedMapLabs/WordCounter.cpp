#include "WordCounter.h"

#include <unordered_map>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

WordCounter::WordCounter(string filePath)
{
    //open a file and read in words
    ifstream infile;
    infile.open(filePath);
    
    if(infile.good())
    {
        string latestWord;
        while(infile.eof() == false)
        {
            infile>>latestWord;

            string cleansedWord = cleanse(latestWord);

            //handle the latest word from the file here
            pair<string, int> dataPoint(cleansedWord, 1);
            
            if (stringHashTable.find(cleansedWord) != stringHashTable.end()) {

                stringHashTable[cleansedWord]++;

            }
            else {

                stringHashTable.insert(dataPoint);

            }
            
            
        }
    }
    else
    {
        cout<<"Error opening file: "<<filePath<<endl;
        exit(0);
    }
}
//--
void WordCounter::cleanse(string& word)
{
    //make uppercase lettters lowercase and remove all non-alphanumeric characters
    for(int i = word.size() - 1;i >= 0;i--)
    {
        //if its a letter
        if(isalnum(word[i]))
        {
            word[i] = tolower(word[i]);
        }
        else //its not a letter
        {
            word.erase(word.begin() + i);
        }
    }
}
//--
size_t WordCounter::getTotalWordCount()
{

    int totalWords = 0;
    //return the total number of words
    for (auto it = stringHashTable.begin(); it != stringHashTable.end(); ++it)
    {
        pair<string, int> dataPoint = *it;

        totalWords += dataPoint.second;
        
    }

    return totalWords;
}
//--
size_t WordCounter::getDistinctWordCount()
{
    //return the total number of distinct words
    return stringHashTable.size();
}
//--
vector < pair < string, int > > WordCounter::getMostUsedWords(int numRequested)
{
    //return a vector of the most used words and their frequencies
}
//--
vector < pair < string, int > > WordCounter::getMostUsedWords(int numRequested, int minLength)
{
    //return a vector of the most used words and their frequencies above a min word length
}
//--
vector < pair < string, int > > WordCounter::getWordsExactFreq(int numRequested)
{
    //return a vector of words used an exact number of times
}