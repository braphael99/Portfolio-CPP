//Blake Raphael
// ProgrammingProject01.cpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "CleansedWord.h"
#include "WordCollection.h"
using namespace std;

int main()
{
	string filePath = "C:/Users/braph/Desktop/Portfolio/CS2_files/conneticutYankee.txt";
	vector < CleansedWord > wordCollection;
	WordCollection collectionTest(filePath);

	cout << "word count: " << collectionTest.getWordCount() << "\n";

	cout << "distinct word count: " << collectionTest.getDistinctWordCount() << "\n";

	wordCollection = collectionTest.getMostUsedWords(5);
	cout << "top 5 most used words: \n";

	for (int i = 0; i < wordCollection.size(); i++) {

		cout << wordCollection[i].getCleansedWord() << " frequency: " << wordCollection[i].getFrequency() << "\n";

	}

	wordCollection = collectionTest.getMostUsedWords(5,4);
	cout << "top 5 most used words with at least 4 characters: \n";

	for (int i = 0; i < wordCollection.size(); i++) {

		cout << wordCollection[i].getCleansedWord() << " frequency: " << wordCollection[i].getFrequency() << "\n";

	}

	wordCollection = collectionTest.getWordsUsed(5);
	cout << "words used 5 times: \n";

	for (int i = 0; i < wordCollection.size(); i++) {

		cout << wordCollection[i].getCleansedWord() << "\n";

	}

}