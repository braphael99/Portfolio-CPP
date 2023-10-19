#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
#include "Deck.h"
#include <ctime>

using namespace std;

enum Ranks {ROYAL_FLUSH, STRAIGHT_FLUSH, FOUR_OF_A_KIND, FULL_HOUSE, FLUSH, STRAIGHT, THREE_OF_A_KIND, TWO_PAIR, PAIR, HIGH_CARD};


class PokerEvaluator
{
public:
	PokerEvaluator(int cardsInHand);
	void setNumberOfHandsToPlay(int numHands);
	void addCardToHand(int cardVal, int cardSuit);
	void playAndDisplay();
private:
	int cardsPerHand;
	int numHandsToPlay;
	vector <Card> cardsInEveryHand;
	vector <int> frequencies;
	void sortHandByValue(vector <Card>& hand);
	void sortHandBySuit(vector <Card>& hand);
	bool isRoyalFlush(vector <Card>& hand);
	bool isStraightFlush(vector <Card>& hand);
	bool isFourOfAKind(vector <Card>& hand);
	bool isFullHouse(vector <Card>& hand);
	bool isFlush(vector<Card>& hand);
	bool isStraight(vector <Card>& hand);
	bool isThreeOfAKind(vector <Card>& hand);
	bool isTwoPair(vector <Card>& hand);
	bool isPair(vector <Card>& hand);
	
};

