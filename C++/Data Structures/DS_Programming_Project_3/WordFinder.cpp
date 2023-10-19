#include "WordFinder.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "WordCombo.h"

WordFinder::WordFinder(string dictionaryPath) {

    letterCounter = 0;

    ifstream infile;

    infile.open(dictionaryPath);

    if (infile.good())
    {
        string line;

        getline(infile, line);

        while (infile.good())
        {
            dictionary.push_back(line);

            getline(infile, line);
        }
    }
    else
    {
        cout << "Cannot open the file: " << dictionaryPath << endl;
    }

}
void WordFinder::replace(char original, char replace) {

    pair<int, char> newReplacement(original, replace);
    replacements.insert(newReplacement);

}
bool WordFinder::makeWordsFromWord(string word, WordCombo& newWord) {

    vector <string> foundWords;
    bool retVal = false;
    newWord.setOriginalWord(word);
    word = cleanse(word);
    letterCounter = 0;

    retVal = makeWordsHelper(word, newWord, foundWords);

    return retVal;

}

bool WordFinder::makeWordsHelper(string word, WordCombo& newWord, vector <string> found) {

    int origWordSize = word.length();
    bool retVal = false;
    bool isWordComplete = false;
    string first;
    string rest;

    for (int i = 0; i <= word.size(); i++) {

        first = word.substr(0, i);
        rest = word.substr(i);

        if (search(first) && rest.length() != 0) {

            found.push_back(first);
            makeWordsHelper(rest, newWord, found);
            
            if (found.size() != 0) {

                found.pop_back();
            
            }
            
            retVal = true;
            
        }
        else if (search(first) && rest.length() == 0) {

            found.push_back(first);
            newWord.addWords(found);

            if (found.size() != 0) {

                 found.pop_back();

            }
            retVal = true;

        }
        else if(rest.length() == 0 && found.size() != 0) {

            found.pop_back();
            
            retVal = true;

        }
        else {

            retVal = true;

        }

    }

    return retVal;

}

string WordFinder::cleanse(string word) {

    string cleansedWord;
    
    for (int i = 0; i < word.length(); i++) {

        if (isalpha(word.at(i))) {
            cleansedWord.push_back(tolower(word.at(i)));
        }
        for (auto it = replacements.begin(); it != replacements.end(); ++it)
        {
            pair <int, char> replaceCheck = *it;

            if (replaceCheck.first == word.at(i)) {

             cleansedWord.push_back(tolower(replaceCheck.second));

            }
        }
    }

    return cleansedWord;

}
bool WordFinder::search(string searchWord) {

	bool retVal = false;
    int start = 0;
    int end = dictionary.size() - 1;
    int middle;

    while (start <= end)
    {
        middle = (start + end) / 2;

        if (searchWord == dictionary[middle])
        {
            retVal = true;
            break;
        }
        else if (searchWord < dictionary[middle])
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }

    return retVal;

}