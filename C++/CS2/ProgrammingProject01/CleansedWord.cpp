#include "CleansedWord.h"

CleansedWord::CleansedWord(string orig, string cleansed) {

	originalWord = orig;
	cleansedWord = cleanse(originalWord);
	frequency = 1;

}

string CleansedWord::getOriginalWord() {

	return originalWord;

}

string CleansedWord::getCleansedWord() {

	return cleansedWord;

}

void CleansedWord::setOriginalWord(string word) {

	originalWord = word;

}

void CleansedWord::setCleansedWord(string word) {

	cleansedWord = cleanse(word);

}

int CleansedWord::getFrequency() {

	return frequency;

}

void CleansedWord::increaseFrequency() {

	frequency++;

}

string CleansedWord::cleanse(string someText) {

	for (int i = 0; i < originalWord.length(); i++) {

		if (isalnum(originalWord.at(i))) {
			cleansedWord.push_back(tolower(originalWord.at(i)));
		}
	}

	return cleansedWord;

}