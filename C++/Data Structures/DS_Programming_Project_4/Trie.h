#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "TrieElement.h";

using namespace std;

class Trie
{
public:
	Trie(string dictionaryPath);
	~Trie();
	string search(const string& word);
	void insert(string word);
	void printAllWords();
	void cleanse(string& word);
private:
	TrieElement* p_root;
};

