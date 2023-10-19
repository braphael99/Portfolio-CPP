#include "BoggleBoard.h"
#include <string>
#include "BoggleDie.h"
#include "Trie.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

BoggleBoard::BoggleBoard(const string& pathToDictionary) {

	Trie* newTrie = new Trie(pathToDictionary);
	dictionary = newTrie;

	for (int i = 0; i < 25; i++) {

		allDice[i] = new BoggleDie();

	}

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			board[i][j] = new BoggleDie();

		}

	}

}

void BoggleBoard::printBoard() {

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			cout << board[i][j]->getValue() << " ";

		}

		cout << "\n";

	}

}

void BoggleBoard::solve() {
	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			string tempWordToAdd = "";
			solveHelper(tempWordToAdd, i, j);

		}

	}
	

}

void BoggleBoard::rollDice() {

	srand(time(NULL));

	int randPos;
	int counter = 0;
	//using loop 25 times pick a random value from each arr and assign to die
	for (int i = 0; i < 25; i++) {

		randPos = rand() % 6;

		allDice[i]->setValue(diceFaces[i][randPos]);

	}

	for (int i = 0; i < 25; i++) {

		randPos = rand() % 25;
		BoggleDie* temp = new BoggleDie(allDice[i]->getValue());

		allDice[i]->setValue(allDice[randPos]->getValue());

		allDice[randPos]->setValue(temp->getValue());

	}

	//SHUFFLE ALLDICE (go back to poker project) and place in sequential order (nested loops)

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			board[i][j]->setValue(allDice[counter]->getValue());
			counter++;

		}

	}

}

void BoggleBoard::solveHelper(string stringSoFar, int xCoord, int yCoord) {

	string next = board[xCoord][yCoord]->getValue();
	bool isDoubleLetter = false;
	if (next.length() > 1) {

		isDoubleLetter = true;

	}

	stringSoFar = stringSoFar + next;
	string searchResult = dictionary->search(stringSoFar);

	if (searchResult == "FOUND" && stringSoFar.length() >= 4) {
		upperCase(stringSoFar);
		if(allWords.size() == 0){
			allWords.push_back(stringSoFar);
		}
		else {
			for (int i = 0; i < allWords.size(); i++) {
				if (allWords[i] == stringSoFar) {

					break;

				}
				else if(allWords[i] != stringSoFar && i == allWords.size() - 1) {

					allWords.push_back(stringSoFar);

				}
			}
		}

		searchResult = "PARTIAL";
	
	}

	if (searchResult == "NOT FOUND") {

		if (isDoubleLetter) {

			stringSoFar = stringSoFar.substr(0, stringSoFar.length() - 2);

		}
		else {

			stringSoFar = stringSoFar.substr(0, stringSoFar.length() - 1);

		}
		return;

	}

	else if (searchResult == "PARTIAL") {

		board[xCoord][yCoord]->setTraverse(true);

		if (xCoord != 4) {

			if (board[xCoord + 1][yCoord]->getTraverse() == false) {

				solveHelper(stringSoFar, xCoord + 1, yCoord);

			}

		}
		if (xCoord != 0) {

			if (board[xCoord - 1][yCoord]->getTraverse() == false) {

				solveHelper(stringSoFar, xCoord - 1, yCoord);

			}

		}
		if (yCoord != 4) {

			if (board[xCoord][yCoord + 1]->getTraverse() == false) {

				solveHelper(stringSoFar, xCoord, yCoord + 1);

			}

		}
		if (yCoord != 0) {

			if (board[xCoord][yCoord - 1]->getTraverse() == false) {

				solveHelper(stringSoFar, xCoord, yCoord - 1);

			}

		}
		if (xCoord != 4 && yCoord != 4) {

			if (board[xCoord + 1][yCoord + 1]->getTraverse() == false) {

				solveHelper(stringSoFar, xCoord + 1, yCoord + 1);

			}

		}
		if (xCoord != 4 && yCoord != 0) {

			if (board[xCoord + 1][yCoord - 1]->getTraverse() == false) {

				solveHelper(stringSoFar, xCoord + 1, yCoord - 1);

			}

		}
		if (xCoord != 0 && yCoord != 4) {

			if (board[xCoord - 1][yCoord + 1]->getTraverse() == false) {

				solveHelper(stringSoFar, xCoord - 1, yCoord + 1);

			}

		}
		if (xCoord != 0 && yCoord != 0) {

			if (board[xCoord - 1][yCoord - 1]->getTraverse() == false) {

				solveHelper(stringSoFar, xCoord - 1, yCoord - 1);

			}

		}

		board[xCoord][yCoord]->setTraverse(false);
	}
	
}

void BoggleBoard::printWords() {

	sort(allWords);

	for (int i = allWords.size() - 1; i >= 0; i--) {

		cout << allWords[i] + "\n";

	}

}

void BoggleBoard::upperCase(string& word) {

	string upperWord;

	for (int i = 0; i < word.length(); i++) {

		if (isalpha(word.at(i))) {
			upperWord.push_back(toupper(word.at(i)));
		}

	}

	word = upperWord;

}

void BoggleBoard::sort(vector <string>& words) {

	for (int i = 0; i < words.size() - 1; i++)
	{
		for (int j = 0; j < words.size() - 1; j++)
		{
			if (words[j].length() > words[j + 1].length())
			{
				string temp = words[j];
				words[j] = words[j + 1];
				words[j + 1] = temp;

			}
		}
	}


}