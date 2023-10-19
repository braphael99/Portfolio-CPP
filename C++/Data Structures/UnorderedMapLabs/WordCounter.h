#pragma once
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class WordCounter
{
public:
    WordCounter(string filePath);
    
    size_t getTotalWordCount();
    size_t getDistinctWordCount();
    
    vector < pair < string, int > > getMostUsedWords(int numRequested);
    vector < pair < string, int > > getMostUsedWords(int numRequested, int minLength);
    vector < pair < string, int > > getWordsExactFreq(int numRequested);

private:
    void cleanse(string& word);
    //more helper methods here

    unordered_map<string, int> stringHashTable;

    //data members here, perhaps an unordered_map
};
