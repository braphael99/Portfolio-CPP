#include "TrieElement.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

TrieElement::TrieElement() {

	isCompleteWord = false;
	wordSoFar = "";

}

TrieElement::TrieElement(string word) {

	isCompleteWord = false;
	wordSoFar = word;

	alphabet = new TrieElement * [26];
	for (int i = 0; i < 26; i++) {

		alphabet[i] = NULL;

	}

}

void TrieElement::insertHelper(string word, TrieElement* p, string x) {
	if (word.length() > 0) {

		string tempWordSoFar;
		int asciiIndex = word[0] - 'a';

		if (p->alphabet[asciiIndex] == NULL) {

			TrieElement* next = new TrieElement(x + word.substr(0, 1));
			p->alphabet[asciiIndex] = next;

		}

		tempWordSoFar = p->alphabet[asciiIndex]->wordSoFar;
		insertHelper(word.substr(1), p->alphabet[asciiIndex], tempWordSoFar);

	}
	else {

		p->isCompleteWord = true;

	}
	

}

string TrieElement::searchHelper(string word, string& returnValue) {
	
	cleanse(word);

	if (word.length() == 0) {

		returnValue = "PARTIAL";

		if (isCompleteWord) {

			returnValue = "FOUND";

		}

	}

	else {

		int asciiIndex = word[0] - 'a';
		if (alphabet[asciiIndex] == NULL) {

			returnValue = "NOT FOUND";
		}
		else {

			alphabet[asciiIndex]->searchHelper(word.substr(1), returnValue);

		}

		

	}

	return returnValue;

}

TrieElement::~TrieElement() {

	for (int i = 0; i < 26; i++) {

		if (alphabet[i] != 0) {

			delete alphabet[i];

		}

	}

}

void TrieElement::printHelper() {

	for (int i = 0; i < 26; i++) {

		if (alphabet[i] != NULL) {

			if (alphabet[i]->isCompleteWord) {

				cout << alphabet[i]->wordSoFar << " \n";

			}
			else
			{

				alphabet[i]->printHelper();

			}

		}

	}


}

void TrieElement::cleanse(string& word) {

	string cleansedWord;

	for (int i = 0; i < word.length(); i++) {

		if (isalpha(word.at(i))) {
			cleansedWord.push_back(tolower(word.at(i)));
		}

	}

	word = cleansedWord;

}