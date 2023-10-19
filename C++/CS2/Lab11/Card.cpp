#include "Card.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

Card::Card(int value, int suit) {

	cardValue = value;
	cardSuit = suit;

}

int Card::getValue() {

	return cardValue;

}

int Card::getSuit() {

	return cardSuit;

}

void Card::setValue(int value) {

	cardValue = value;

}

void Card::setSuit(int suit) {

	cardSuit = suit;

}

string Card::print() {

	string output;

	if (cardValue == 1) {

		output = "A of " + to_string(cardSuit) + "\n ";
		return output;

	}
	
	else if (cardValue == 11) {

		return "J of " + to_string(cardSuit) + "\n ";

	}

	else if (cardValue == 12) {

		return "Q of " + to_string(cardSuit) + "\n ";

	}

	else if (cardValue == 13) {

		return "K of " + to_string(cardSuit) + "\n ";

	}

	else {

		return to_string(cardValue) + " of " + to_string(cardSuit) + "\n ";

	}

}