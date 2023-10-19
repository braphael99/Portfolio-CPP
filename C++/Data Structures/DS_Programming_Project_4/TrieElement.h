#pragma once

#include <vector>
#include <string>

using namespace std;

class TrieElement
{
public:
	TrieElement();
	TrieElement(string word);
	void insertHelper(string word, TrieElement* p, string x);
	string searchHelper(string word, string& returnValue);
	~TrieElement();
	void printHelper();

private:
	bool isCompleteWord;
	string wordSoFar;
	TrieElement** alphabet;
	void cleanse(string& word);
};

