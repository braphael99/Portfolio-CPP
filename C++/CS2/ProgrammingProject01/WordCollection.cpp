#include "WordCollection.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "CleansedWord.h"

WordCollection::WordCollection(string path)
	: allWords(27)
{

	ifstream infile;

	infile.open(path);

	if (infile.good()) {
		string word;
		bool isRepeated = false;
		int repeatLoc = -1;

		while (infile.good()) {
			infile >> word;
			isRepeated = false;

			CleansedWord temp(word, "");

			int firstLetterTemp = temp.getCleansedWord()[0] - 97;

			if (firstLetterTemp < 0) {

				firstLetterTemp = 26;

			}

			for (int i = allWords[firstLetterTemp].size() - 1; i >= 0; i--) {

				if (temp.getCleansedWord() == allWords[firstLetterTemp][i].getCleansedWord()) {

					isRepeated = true;
					repeatLoc = i;

				}

			}

			if (isRepeated) {

				allWords[firstLetterTemp][repeatLoc].increaseFrequency();

			}
			else if(temp.getCleansedWord() != "") {

				allWords[firstLetterTemp].push_back(temp);

			}
			
		}

	}
	else {
		cout << "Cannot open the file: " << path << "\n";
	}

	for (int i = allWords.size() - 1; i >= 0; i--) {

		for (int j = allWords[i].size() - 1; j >= 0; j--) {

			cleansedWords.push_back(allWords[i][j]);

		}

	}

}

int WordCollection::getWordCount() {

	int total = 0;

	for (int i = 0; i < cleansedWords.size(); i++) {

		total += cleansedWords[i].getFrequency();

	}

	return total;

}

int WordCollection::getDistinctWordCount() {

	return cleansedWords.size();

}

int WordCollection::findMostFrequent(int freqNotToExceed) {
	int maxSoFar = -1;

	for (int i = 0; i < cleansedWords.size(); i++) {

		if (cleansedWords[i].getFrequency() > maxSoFar && cleansedWords[i].getFrequency() < freqNotToExceed) {

			maxSoFar = cleansedWords[i].getFrequency();

		}

	}
	
	return maxSoFar;

}

void WordCollection::collectWords(int freq, vector <CleansedWord>& words) {

	for (int i = 0; i < cleansedWords.size(); i++) {

		if (cleansedWords[i].getFrequency() == freq) {

			words.push_back(cleansedWords[i]);

		}

	}

}

void WordCollection::collectWords(int freq, int minLetters, vector <CleansedWord>& words) {

	for (int i = 0; i < cleansedWords.size(); i++) {

		if (cleansedWords[i].getFrequency() == freq && cleansedWords[i].getCleansedWord().length() >= minLetters) {

			words.push_back(cleansedWords[i]);

		}

	}

}

vector <CleansedWord> WordCollection::getMostUsedWords(int numTopWords) {
	vector <CleansedWord> topWords;
	int maxFrequency = findMostFrequent(INT_MAX);
	collectWords(maxFrequency, topWords);

	while (topWords.size() < numTopWords) {

		maxFrequency = findMostFrequent(maxFrequency);
		collectWords(maxFrequency, topWords);

	}

	topWords.erase(topWords.begin() + numTopWords, topWords.begin() + topWords.size());

	return topWords;
}

vector <CleansedWord> WordCollection::getMostUsedWords(int numTopWords, int minWordLength) {
	vector <CleansedWord> topWords;
	int maxFrequency = findMostFrequent(INT_MAX);
	collectWords(maxFrequency, minWordLength, topWords);

	while (topWords.size() < numTopWords) {

		maxFrequency = findMostFrequent(maxFrequency);
		collectWords(maxFrequency, minWordLength, topWords);

	}

	topWords.erase(topWords.begin() + numTopWords, topWords.begin() + topWords.size());

	return topWords;
}

vector <CleansedWord> WordCollection::getWordsUsed(int usedNumTimes) {
	vector <CleansedWord> wordsUsed;

	for (int i = 0; i < cleansedWords.size(); i++) {

		if (cleansedWords[i].getFrequency() == usedNumTimes) {

			wordsUsed.push_back(cleansedWords[i]);

		}

	}

	return wordsUsed;
}
