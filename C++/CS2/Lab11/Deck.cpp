#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

Deck::Deck() {

	for (int val = 2; val <= ACE; val++) {

		for (int suit = CLUBS; suit <= SPADES; suit++) {

			Card temp(val, suit);
			allCards.push_back(temp);

		}

	}

}

void Deck::shuffle() {

		srand(time(0));

		for (int i = 0; i < allCards.size(); i++) {

			int randPos = rand() % allCards.size();
			Card temp(allCards[i].getValue(), allCards[i].getSuit());

			allCards[i].setValue(allCards[randPos].getValue());
			allCards[i].setSuit(allCards[randPos].getSuit());

			allCards[randPos].setValue(temp.getValue());
			allCards[randPos].setSuit(temp.getSuit());


		}

}

void Deck::printAllCards() {

	for (int i = 0; i < allCards.size(); i++) {

		cout << "Value: " << allCards[i].getValue() << "\n";
		cout << "Suit: " << allCards[i].getSuit() << "\n";

	}

}

bool Deck::getCards(int numRequestedCards, vector <Card>& cards) {

	int numCardsToAdd = allCards.size() - numRequestedCards;

	if (numRequestedCards <= allCards.size()) {

		for (int i = allCards.size() - 1; i >= numCardsToAdd; i--) {

			Card temp = Card(allCards[i].getValue(), allCards[i].getSuit());

			cards.push_back(temp);
			allCards.erase(allCards.begin() + i);

		}

		return true;

	}
	else {

		return false;

	}

}


void Deck::addCardsBackToDeck(const vector <Card>& cards) {

	for (int i = 0; i < cards.size(); i++) {

		allCards.push_back(cards[i]);

	}

}

void Deck::removeCards(vector <Card>& removeCards) {

	for (int i = 0; i < allCards.size(); i++) {

		for (int j = 0; j < removeCards.size(); j++) {

			if (allCards[i].getSuit() == removeCards[j].getSuit() && allCards[i].getValue() == removeCards[j].getValue()) {

				allCards.erase(allCards.begin() + i);

			}

		}

	}

}