#include "Trie.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

Trie::Trie(string dictionaryPath) {
    TrieElement* first = new TrieElement("");
    p_root = first;


    ifstream infile;

    infile.open(dictionaryPath);

    if (infile.good())
    {
        string line;

        getline(infile, line);

        cleanse(line);

        while (infile.good())
        {
            
            insert(line);

            getline(infile, line);

            cleanse(line);

        }
    }
    else
    {
        cout << "Cannot open the file: " << dictionaryPath << endl;
    }

}

Trie::~Trie() {

    delete p_root;
    p_root = 0;

}

string Trie::search(const string& word) {

    string retVal = "";

    return p_root->searchHelper(word, retVal);

}

void Trie::insert(string word) {

    p_root->insertHelper(word, p_root, "");

}

void Trie::printAllWords() {

    p_root->printHelper();

}

void Trie::cleanse(string& word) {

    string cleansedWord;

    for (int i = 0; i < word.length(); i++) {

        if (isalpha(word.at(i))) {
            cleansedWord.push_back(tolower(word.at(i)));
        }
        
    }

    word = cleansedWord;

}