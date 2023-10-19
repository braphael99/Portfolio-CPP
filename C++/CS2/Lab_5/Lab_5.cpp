// Lab_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct CleansedWord {
    string originalWord;
    string cleansedWord;
    int frequency;

};

void readFile(const string& filePath, vector < string >& words);
CleansedWord cleanse(string someText);
int search(const CleansedWord& word, const vector <CleansedWord >& words);
void printWords(const vector < CleansedWord >& words);

int main()
{
	string poemPath = "C:/Users/braph/Desktop/Portfolio/CS2_files/sqrt110.txt";
	
	vector < string > uncleansedWords;
	vector < CleansedWord > allWords;

	readFile(poemPath, uncleansedWords);
	//printWords(allWords);

	return 0;
}

void readFile(const string& filePath, vector < string >& words)
{
			ifstream infile;

			infile.open(filePath);

			if (infile.good()) {
				string word;

				infile >> word;

				while (infile.good()) {
					words.push_back(word);

					infile >> word;
				}
			}
			else {
				cout << "Cannot open the file: " << filePath << "\n";
			}

	}


CleansedWord cleanse(string someText)
{
	CleansedWord word;

	word.originalWord = someText;
	word.cleansedWord = someText;
	word.frequency = 0;

	for (int i = 0; i < someText.length(); i++) {
		
		if (isalnum(someText.at(i))) {
			word.cleansedWord = tolower(someText.at(i));
		}	
	}

	return word;
}

int search(const CleansedWord& word, const vector <CleansedWord >& words) {

	return 0;
}

void printWords(const vector < CleansedWord >& words) {
	for (int i = 0; i < words.size(); i++)
	{
		cout << words[i].cleansedWord << " " << words[i].frequency << "\n";
	}
}
