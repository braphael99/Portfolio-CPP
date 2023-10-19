#pragma once
#include <string>
#include <vector>
#include "CleansedWord.h"

using namespace std;

class WordCollection
{
public:
	WordCollection(string path);
	int getWordCount();
	int getDistinctWordCount();
	vector <CleansedWord> getMostUsedWords(int numTopWords);
	vector <CleansedWord> getMostUsedWords(int numTopWords, int minWordLength);
	vector <CleansedWord> getWordsUsed(int usedNumTimes);
private:
	int findMostFrequent(int freqNotToExceed);
	void collectWords(int freq, vector <CleansedWord>& words);
	void collectWords(int freq, int minLetters, vector <CleansedWord>& words);
	vector <CleansedWord> cleansedWords;
	vector <vector <CleansedWord>> allWords;
};

