#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

enum CardSuit{CLUBS, DIAMONDS, HEARTS, SPADES};
enum CardValue{JACK = 11, QUEEN, KING, ACE};

class Card
{
public:
	Card(int value, int suit);
	int getValue();
	int getSuit();
	void setValue(int value);
	void setSuit(int suit);
	string print();
private:

	int cardValue;
	int cardSuit;

};

