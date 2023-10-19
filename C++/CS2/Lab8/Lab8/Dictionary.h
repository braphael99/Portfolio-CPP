#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


class Dictionary
{
public:
	Dictionary(string dictionaryPath);
	Dictionary(const vector <string>& dictionaryPaths);
	~Dictionary();

	void addWordToDictionary(string newWord);
	void spellCheck(string filePath);
	bool search(string searchWord);
	vector < string > findMisspellings(string filePath);
	void createNewDictionaryFile(string newFilePath);
private:
	bool createdFromSingleFile;
	bool wordsAdded;
	string originalDictionaryPath;
	vector <string> sortedDictionary;
	vector <string> originalFileContents;
	vector <char> alphabet { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
		'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	void sort(vector <string>& sortedDictionary);
	int searchForInsertPosition(string searchWord);
	string cleanse(string uncleansedWord);
	void addSuggestedWord(string suggestion, vector<string>& suggestedWords);
	void findClosest(string word, vector <string>& suggestedWords);
	void printSuggestions(vector <string>& suggestedWords);
	void replaceLetters(string word, vector <string>& suggestedWords);
	void swapLetters(const string& word, vector <string>& suggestedWords);

};

