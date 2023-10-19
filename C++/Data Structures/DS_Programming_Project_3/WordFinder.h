#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "WordCombo.h"
#include <unordered_map>

using namespace std;

class WordFinder
{
public:
    WordFinder(string dictionaryPath);
    void replace(char original, char replace);
    bool makeWordsFromWord(string word, WordCombo& newWord);
    bool search(string searchWord);
private:
    vector <string> dictionary;
    int letterCounter;
    string cleanse(string word);
    bool makeWordsHelper(string word, WordCombo& newWord, vector <string> foundWords);
    unordered_map<int, char> replacements;
    
};

