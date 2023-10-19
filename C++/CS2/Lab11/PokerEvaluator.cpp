#include "PokerEvaluator.h"
#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
#include "Deck.h"
#include <ctime>

using namespace std;

PokerEvaluator::PokerEvaluator(int cardsInHand)
	: frequencies(10)
{

	cardsPerHand = cardsInHand;
	numHandsToPlay = 100000;

}

void PokerEvaluator::setNumberOfHandsToPlay(int numHands) {

	numHandsToPlay = numHands;

}

void PokerEvaluator::addCardToHand(int cardVal, int cardSuit) {

	Card newCard(cardVal, cardSuit);

	cardsInEveryHand.push_back(newCard);

}

void PokerEvaluator::playAndDisplay() {

	Deck testDeck = Deck();

	testDeck.removeCards(cardsInEveryHand);

	vector <Card> currentHand;

	for (int i = 0; i < numHandsToPlay; i++) {

		testDeck.shuffle();

		currentHand = cardsInEveryHand;

		testDeck.getCards(cardsPerHand - cardsInEveryHand.size(), currentHand);

		if (isRoyalFlush(currentHand)) {

			frequencies[ROYAL_FLUSH]++;

		}
		else if (isStraightFlush(currentHand)) {

			frequencies[STRAIGHT_FLUSH]++;

		}
		else if (isFourOfAKind(currentHand)) {

			frequencies[FOUR_OF_A_KIND]++;

		}
		else if (isFullHouse(currentHand)) {

			frequencies[FULL_HOUSE]++;

		}
		else if (isFlush(currentHand)) {

			frequencies[FLUSH]++;

		}
		else if (isStraight(currentHand)) {

			frequencies[STRAIGHT]++;

		}
		else if (isThreeOfAKind(currentHand)) {

			frequencies[THREE_OF_A_KIND]++;

		}
		else if (isTwoPair(currentHand)) {

			frequencies[TWO_PAIR]++;

		}
		else if (isPair(currentHand)) {

			frequencies[PAIR]++;

		}
		else {

			frequencies[HIGH_CARD]++;

		}

		testDeck.addCardsBackToDeck(currentHand);
		currentHand.clear();

	}

	cout << "Royal Flush: " << (double)frequencies[ROYAL_FLUSH] / (double)numHandsToPlay * 100 << "\n";
	cout << "Straight Flush: " << (double)frequencies[STRAIGHT_FLUSH] / (double)numHandsToPlay * 100 << "\n";
	cout << "Four of a Kind: " << (double)frequencies[FOUR_OF_A_KIND] / (double)numHandsToPlay * 100 << "\n";
	cout << "Full House: " << (double)frequencies[FULL_HOUSE] / (double)numHandsToPlay * 100 << "\n";
	cout << "Flush: " << (double)frequencies[FLUSH] / (double)numHandsToPlay * 100 << "\n";
	cout << "Straight: " << (double)frequencies[STRAIGHT] / (double)numHandsToPlay * 100 << "\n";
	cout << "Three of a Kind: " << (double)frequencies[THREE_OF_A_KIND] / (double)numHandsToPlay * 100 << "\n";
	cout << "Two Pair: " << (double)frequencies[TWO_PAIR] / (double)numHandsToPlay * 100 << "\n";
	cout << "Pair: " << (double)frequencies[PAIR] / (double)numHandsToPlay * 100 << "\n";
	cout << "High Card: " << (double)frequencies[HIGH_CARD] / (double)numHandsToPlay * 100 << "\n";

	frequencies.clear();

}

void PokerEvaluator::sortHandByValue(vector <Card>& hand) {

	int lowJ;

	for (int i = 0; i < hand.size(); i++) {

		lowJ = i;

		for (int j = i + 1; j < hand.size(); j++)
		{
			if (hand[j].getValue() < hand[lowJ].getValue())
			{

				lowJ = j;

			}
		}

		Card temp = Card(hand[i].getValue(), hand[i].getSuit());
		
		hand[i].setSuit(hand[lowJ].getSuit());
		hand[i].setValue(hand[lowJ].getValue());
		
		hand[lowJ].setSuit(temp.getSuit());
		hand[lowJ].setValue(temp.getValue());

	}

}

void PokerEvaluator::sortHandBySuit(vector <Card>& hand) {

	int lowJ;

	for (int i = 0; i < hand.size(); i++) {

		lowJ = i;

		for (int j = i+1; j < hand.size(); j++)
		{
			if (hand[j].getSuit() < hand[lowJ].getSuit())
			{
				
				lowJ = j;

			}
		}

		Card temp = Card(hand[i].getValue(), hand[i].getSuit());

		hand[i].setSuit(hand[lowJ].getSuit());
		hand[i].setValue(hand[lowJ].getValue());

		hand[lowJ].setSuit(temp.getSuit());
		hand[lowJ].setValue(temp.getValue());

	}

}

bool PokerEvaluator::isRoyalFlush(vector <Card>& hand) {

	sortHandByValue(hand);

	if (cardsPerHand == 5) {

		if (isStraight(hand) && isFlush(hand) && hand[4].getValue() == ACE) {

			return true;

		}
		else {

			return false;

		}
		

	}
	else if (cardsPerHand == 7) {

		if (hand[4].getValue() == ACE || hand[5].getValue() == ACE || hand[6].getValue() == ACE) {

			if (isStraight(hand) && isFlush(hand)) {

				return true;

			}
			else {

				return false;

			}

		}

	}

	return false;

}

bool PokerEvaluator::isStraightFlush(vector <Card>& hand) {

	if (isStraight(hand) && isFlush(hand)) {

		return true;

	}
	else {

		return false;

	}

}

bool PokerEvaluator::isFourOfAKind(vector <Card>& hand) {

	sortHandByValue(hand);

	if (cardsPerHand == 5) {

		if (hand[0].getValue() == hand[1].getValue() &&
			hand[1].getValue() == hand[2].getValue() &&
			hand[2].getValue() == hand[3].getValue()) {

			return true;

		}
		else if (hand[1].getValue() == hand[2].getValue() &&
				 hand[2].getValue() == hand[3].getValue() &&
				 hand[3].getValue() == hand[4].getValue()) {

			return true;

		}

	}
	else if (cardsPerHand == 7) {

		if (hand[0].getValue() == hand[1].getValue() &&
			hand[1].getValue() == hand[2].getValue() &&
			hand[2].getValue() == hand[3].getValue()) {

			return true;

		}
		else if (hand[1].getValue() == hand[2].getValue() &&
			hand[2].getValue() == hand[3].getValue() &&
			hand[3].getValue() == hand[4].getValue()) {

			return true;

		}

		else if (hand[2].getValue() == hand[3].getValue() &&
			hand[2].getValue() == hand[4].getValue() &&
			hand[3].getValue() == hand[5].getValue()) {

			return true;

		}

		else if (hand[3].getValue() == hand[4].getValue() &&
			hand[4].getValue() == hand[5].getValue() &&
			hand[5].getValue() == hand[6].getValue()) {

			return true;

		}
		
		
	}
	
	return false;

}

bool PokerEvaluator::isFullHouse(vector <Card>& hand) {

	sortHandByValue(hand);

	if (cardsPerHand == 5) {

		if (hand[0].getValue() == hand[1].getValue() &&
			hand[1].getValue() == hand[2].getValue() &&
			hand[3].getValue() == hand[4].getValue()) {

			return true;

		}
		else if (hand[0].getValue() == hand[1].getValue() &&
			hand[2].getValue() == hand[3].getValue() &&
			hand[3].getValue() == hand[4].getValue()) {

			return true;

		}

	}
	else if (cardsPerHand == 7) {

		if (hand[0].getValue() == hand[1].getValue() &&
			hand[1].getValue() == hand[2].getValue() &&
			hand[3].getValue() == hand[4].getValue()) {

			return true;

		}
		else if (hand[0].getValue() == hand[1].getValue() &&
			hand[2].getValue() == hand[3].getValue() &&
			hand[3].getValue() == hand[4].getValue()) {

			return true;

		}
		else if (hand[1].getValue() == hand[2].getValue() &&
			hand[3].getValue() == hand[4].getValue() &&
			hand[4].getValue() == hand[5].getValue()) {

			return true;

		}
		else if (hand[2].getValue() == hand[3].getValue() &&
			hand[4].getValue() == hand[5].getValue() &&
			hand[5].getValue() == hand[6].getValue()) {

			return true;

		}

		else if (hand[0].getValue() == hand[1].getValue() &&
			hand[4].getValue() == hand[5].getValue() &&
			hand[5].getValue() == hand[6].getValue()) {

			return true;

		}

		else if (hand[0].getValue() == hand[1].getValue() &&
			hand[1].getValue() == hand[2].getValue() &&
			hand[5].getValue() == hand[6].getValue()) {

			return true;

		}

		else if (hand[1].getValue() == hand[2].getValue() &&
			hand[2].getValue() == hand[3].getValue() &&
			hand[4].getValue() == hand[5].getValue()) {

			return true;

		}

		else if (hand[2].getValue() == hand[3].getValue() &&
			hand[3].getValue() == hand[4].getValue() &&
			hand[5].getValue() == hand[6].getValue()) {

			return true;

		}

	}

	return false;

}

bool PokerEvaluator::isFlush(vector<Card>& hand) {

	bool foundFlush = false;

	sortHandBySuit(hand);

	if (cardsPerHand == 5) {

		if (hand[0].getSuit() == hand[4].getSuit()) {

			foundFlush = true;

		}

	}
	else if (cardsPerHand == 7){

		if (hand[0].getSuit() == hand[4].getSuit()
			|| hand[1].getSuit() == hand[5].getSuit()
			|| hand[2].getSuit() == hand[6].getSuit()) {

			foundFlush = true;

		}

	}

	return foundFlush;

}

bool PokerEvaluator::isStraight(vector <Card>& hand) {

	bool aceOne, aceTwo;
	int testValue = -1;

	if (cardsPerHand == 5) {
		
		sortHandByValue(hand);

		if (hand[4].getValue() == ACE) {

			if (hand[0].getValue() == 2 && hand[1].getValue() == 3 &&
				hand[2].getValue() == 4 && hand[3].getValue() == 5) {

				return true;

			}
			else if (hand[0].getValue() == 10 && hand[1].getValue() == JACK &&
				hand[2].getValue() == QUEEN && hand[3].getValue() == KING) {

				return true;

			}

		}
		else if(hand[4].getValue() == hand[3].getValue() + 1 &&
			hand[3].getValue() == hand[2].getValue() + 1 &&
			hand[2].getValue() == hand[1].getValue() + 1 &&
			hand[1].getValue() == hand[0].getValue() + 1){

			return true;
			
		}

	}
	else if(cardsPerHand == 7){

		sortHandByValue(hand);

		if (hand[4].getValue() == ACE) {

			if (hand[0].getValue() == 2 && hand[1].getValue() == 3 &&
				hand[2].getValue() == 4 && hand[3].getValue() == 5) {

				return true;

			}
			else if (hand[0].getValue() == 10 && hand[1].getValue() == JACK &&
				hand[2].getValue() == QUEEN && hand[3].getValue() == KING) {

				return true;

			}

		}
		else if (hand[4].getValue() == hand[3].getValue() + 1 &&
			hand[3].getValue() == hand[2].getValue() + 1 &&
			hand[2].getValue() == hand[1].getValue() + 1 &&
			hand[1].getValue() == hand[0].getValue() + 1) {

			return true;

		}

	}

	return false;
}

bool PokerEvaluator::isThreeOfAKind(vector <Card>& hand) {

	bool threesOne, threesTwo, threesThree, threesFour, threesFive = false;
	sortHandByValue(hand);

	if (isFourOfAKind(hand) || isFullHouse(hand)) {

		return false;

	}
	else if (cardsPerHand == 5) {

		if (hand[0].getValue() == hand[1].getValue() &&
			hand[1].getValue() == hand[2].getValue()) {

			return true;

		}
		else if (hand[1].getValue() == hand[2].getValue() &&
			hand[2].getValue() == hand[3].getValue()) {

			return true;

		}
		else if (hand[2].getValue() == hand[3].getValue() &&
			hand[3].getValue() == hand[4].getValue()) {

			return true;

		}

	}
	else if (cardsPerHand == 7) {

		if (hand[0].getValue() == hand[1].getValue() &&
			hand[1].getValue() == hand[2].getValue()) {

			return true;

		}

		if (hand[1].getValue() == hand[2].getValue() &&
			hand[2].getValue() == hand[3].getValue()) {

			return true;

		}
		else if (hand[2].getValue() == hand[3].getValue() &&
			hand[3].getValue() == hand[4].getValue()) {

			return true;

		}
		else if(hand[3].getValue() == hand[4].getValue() &&
			hand[4].getValue() == hand[5].getValue()) {

			return true;

		}

		else if(hand[4].getValue() == hand[5].getValue() &&
			hand[5].getValue() == hand[6].getValue()) {

			return true;

		}

	}

	return false;

}

bool PokerEvaluator::isTwoPair(vector <Card>& hand) {

	bool twoPairOne, twoPairTwo, twoPairThree, twoPairFour, twoPairFive, twoPairSix;

	sortHandByValue(hand);

	if (isFourOfAKind(hand) || isFullHouse(hand) || isThreeOfAKind(hand)) {

		return false;

	}
	else if (cardsPerHand == 5) {

		if (hand[0].getValue() == hand[1].getValue() &&
			hand[2].getValue() == hand[3].getValue()) {

			return true;

		}

		else if (hand[1].getValue() == hand[2].getValue() &&
			hand[3].getValue() == hand[4].getValue()) {

			return true;

		}

		else if(hand[0].getValue() == hand[1].getValue() &&
			hand[3].getValue() == hand[4].getValue()) {

			return true;

		}

	}
	else if (cardsPerHand == 7) {

		if (hand[0].getValue() == hand[1].getValue() &&
			hand[2].getValue() == hand[3].getValue()) {

			return true;

		}

		else if (hand[1].getValue() == hand[2].getValue() &&
			hand[3].getValue() == hand[4].getValue()) {

			return true;

		}

		else if (hand[3].getValue() == hand[4].getValue() &&
			hand[5].getValue() == hand[6].getValue()) {

			return true;

		}

		else if (hand[0].getValue() == hand[1].getValue() &&
			hand[3].getValue() == hand[4].getValue()) {

			return true;

		}

		else if (hand[1].getValue() == hand[2].getValue() &&
			hand[5].getValue() == hand[6].getValue()) {

			return true;

		}

		else if (hand[0].getValue() == hand[1].getValue() &&
			hand[5].getValue() == hand[6].getValue()) {

			return true;

		}

	}

	return false;

}

bool PokerEvaluator::isPair(vector <Card>& hand) {

	bool pairOne, pairTwo, pairThree, pairFour, pairFive, pairSix;

	sortHandByValue(hand);

	if (isFourOfAKind(hand) || isFullHouse(hand) || isThreeOfAKind(hand) || isTwoPair(hand)) {

		return false;

	}
	else if (cardsPerHand == 5) {

		if (hand[0].getValue() == hand[1].getValue()) {

			return true;

		}

		else if (hand[1].getValue() == hand[2].getValue()) {

			return true;

		}
		else if (hand[2].getValue() == hand[3].getValue()) {

			return true;

		}
		else if (hand[3].getValue() == hand[4].getValue()) {

			return true;

		}

	}
	else if (cardsPerHand == 7) {

		if (hand[0].getValue() == hand[1].getValue()) {

			return true;

		}

		else if (hand[1].getValue() == hand[2].getValue()) {

			return true;

		}

		else if (hand[2].getValue() == hand[3].getValue()) {

			return true;

		}

		else if (hand[3].getValue() == hand[4].getValue()) {

			return true;

		}

		else if (hand[4].getValue() == hand[5].getValue()) {

			return true;

		}

		else if (hand[5].getValue() == hand[6].getValue()) {

			return true;

		}

	}

	return false;

}
