#pragma once
#include <string>
#include <vector>

using namespace std;

class CleansedWord
{
public:
    CleansedWord(string orig, string cleansed);
    string getOriginalWord();
    string getCleansedWord();
    void setOriginalWord(string word);
    void setCleansedWord(string word);
    int getFrequency();
    void increaseFrequency();
    string cleanse(string someText);
private:
    string originalWord;
    string cleansedWord;
    int frequency;
};

