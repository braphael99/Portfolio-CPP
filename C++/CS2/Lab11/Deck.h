#pragma once
#include "Card.h"
#include <vector>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Deck
{
public:
	Deck();
	void shuffle();
	void printAllCards();
	bool getCards(int numRequestedCards, vector <Card>& cards);
	void addCardsBackToDeck(const vector <Card>& cards);
	void removeCards(vector <Card>& removeCards);
private:
	vector <Card> allCards;

};

