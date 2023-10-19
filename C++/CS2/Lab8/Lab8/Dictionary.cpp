#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Dictionary::Dictionary(string dictionaryPath) {

	createdFromSingleFile = true;
	wordsAdded = false;
	originalDictionaryPath = dictionaryPath;

	ifstream infile;

	infile.open(dictionaryPath);

	if (infile.good()) {
		string word;

		while (infile.good()) {
			
			infile >> word;

			word = cleanse(word);

			if (word.length() > 0 && search(word) == false) {

				int pos = searchForInsertPosition(word);
				sortedDictionary.insert(sortedDictionary.begin() + pos, word);

			}
		}
	}
	else {
		cout << "Cannot open the file : " << dictionaryPath << "\n";
	}


}

Dictionary::Dictionary(const vector <string>& dictionaryPaths) {

	createdFromSingleFile = false;
	wordsAdded = false;
	originalDictionaryPath = "";

	ifstream infile;

	for (int i = 0; i < dictionaryPaths.size(); i++) {


		infile.open(dictionaryPaths[i]);

		if (infile.good()) {
			string word;

			while (infile.good()) {
				infile >> word;

				word = cleanse(word);

				if (word.length() > 0 && search(word) == false) {

					int pos = searchForInsertPosition(word);
					sortedDictionary.insert(sortedDictionary.begin() + pos, word);

				}
			}
		}
		else {
			cout << "Cannot open the file(s) : \n";
		}
	}

}

Dictionary::~Dictionary() {

	if (createdFromSingleFile && wordsAdded) {

		createNewDictionaryFile(originalDictionaryPath);

	}

}

void Dictionary::spellCheck(string filePath) {

	ifstream infile;

	infile.open(filePath);

	if (infile.good()) {
		string word;

		while (infile.good()) {

			infile >> word;

			originalFileContents.push_back(word);

			word = cleanse(word);

			if (word.length() > 0 && search(word) == false && word[0] >= 97) {

				cout << word << " is spelled incorrectly, here are some suggestions: \n\n";

				vector <string> suggestedWords;
				replaceLetters(word, suggestedWords);
				swapLetters(word, suggestedWords);
				findClosest(word, suggestedWords);

				printSuggestions(suggestedWords);

			}
		}
	}
	else {
		cout << "Cannot open the file : " << filePath << "\n";
	}


}

bool Dictionary::search(string searchWord) {

	bool isContained = false;

	int start = 0;
	int end = sortedDictionary.size() - 1;
	int middle;

	while (start <= end) {

		middle = (start + end) / 2;

		if (searchWord == sortedDictionary[middle]) {

			isContained = true;
			break;

		}
		else if (searchWord < sortedDictionary[middle]){

			end = middle - 1;

		}
		else {

			start = middle + 1;
		}
	}

	return isContained;
}

vector < string > Dictionary::findMisspellings(string filePath) {

	vector <string> misspelledWords;

	ifstream infile;

	infile.open(filePath);

	if (infile.good()) {
		string word;

		while (infile.good()) {

			infile >> word;

			word = cleanse(word);

			if (search(word) == false) {

				misspelledWords.push_back(word);

			}
		}
	}
	else {
		cout << "Cannot open the file : " << filePath << "\n";
	}

	return misspelledWords;

}

void Dictionary::createNewDictionaryFile(string newFilePath) {

	ofstream outfile;

	outfile.open(newFilePath);

	if (outfile.good())
	{
		for (int i = 0; i < sortedDictionary.size(); i++)
		{
			outfile << sortedDictionary[i] << endl;
		}
	}
	else
	{
		cout << "Error opening the file: " << newFilePath << endl;
	}

}

void Dictionary::sort(vector <string>& sortedDictionary) {

	for (int i = 0; i < sortedDictionary.size() - 1; i++)
	{
		for (int j = 0; j < sortedDictionary.size() - 1; j++)
		{
			if (sortedDictionary[j] > sortedDictionary[j + 1])
			{
				string temp = sortedDictionary[j];
				sortedDictionary[j] = sortedDictionary[j + 1];
				sortedDictionary[j + 1] = temp;
			}
		}
	}

	for(int i = sortedDictionary.size() - 2; i >= 0; i--) {

		if (i == i + 1) {

			sortedDictionary.erase(sortedDictionary.begin() + (i + 1));
		}

	}
}

int Dictionary::searchForInsertPosition(string searchWord) {
	int pos = -1;
	int start = 0;
	int end = sortedDictionary.size() - 1;
	int middle;

	while (start <= end)
	{
		middle = (start + end) / 2;
		if (searchWord <= sortedDictionary[middle])
		{
			end = middle - 1;
		}
		else
		{
			start = middle + 1;
		}
	}

	pos = start;

	return pos;

}

string Dictionary::cleanse(string uncleansedWord) {
	string cleansedWord;
	
	for (int i = 0; i < uncleansedWord.length(); i++) {

		if (isalnum(uncleansedWord.at(i))) {
			cleansedWord.push_back(tolower(uncleansedWord.at(i)));
		}
	}

	return cleansedWord;

}

void Dictionary::addSuggestedWord(string suggestion, vector<string>& suggestedWords) {
	bool shouldAdd = true;

	for (int i = 0; i < suggestedWords.size(); i++) {

		if (suggestion == suggestedWords[i]) {

			shouldAdd = false;
			break;
		}
	}

	if (shouldAdd) {

		suggestedWords.push_back(suggestion);

	}

}

void Dictionary::addWordToDictionary(string newWord) {

	string cleansedWord = cleanse(newWord);
	bool isFound = search(cleansedWord);
	int pos = -1;

	if (isFound == false) {

		pos = searchForInsertPosition(cleansedWord);
		sortedDictionary.insert(sortedDictionary.begin() + pos, cleansedWord);
		wordsAdded = true;

	}
}

void Dictionary::printSuggestions(vector <string>& suggestedWords) {

	for (int i = 0; i < suggestedWords.size(); i++) {

		cout << "Suggested word " << i + 1 << ": " << suggestedWords[i] << "\n";
	}

}

void Dictionary::findClosest(string word, vector <string>& suggestedWords) {

	int pos = -1;

	pos = searchForInsertPosition(word);

	addSuggestedWord(sortedDictionary[pos - 1], suggestedWords);
	addSuggestedWord(sortedDictionary[pos], suggestedWords);
	addSuggestedWord(sortedDictionary[pos + 1], suggestedWords);

}

void Dictionary::replaceLetters(string word, vector <string>& suggestedWords) {

	string tempWord = cleanse(word);

	for (int i = 0; i < word.length(); i++) {
		for (int j = 0; j < alphabet.size(); j++) {

			tempWord[i] = alphabet[j];

			if (search(tempWord)) {

				addSuggestedWord(tempWord, suggestedWords);

			}
		}

	}

}

void Dictionary::swapLetters(const string& word, vector <string>& suggestedWords) {

	for (int i = 0; i < word.length()- 1; i++) {

		string copiedWord = cleanse(word);
		char letter = copiedWord[i];
		copiedWord[i] = copiedWord[i + 1];
		copiedWord[i + 1] = letter;

		if (search(copiedWord)) {

			addSuggestedWord(copiedWord, suggestedWords);
		}

	}

}