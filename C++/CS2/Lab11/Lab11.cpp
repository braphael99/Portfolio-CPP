// Lab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "PokerEvaluator.h"
#include <ctime>


using namespace std;

int main()
{
        //five card evaluator
        //create a poker evaluator for 5 card poker
        PokerEvaluator fiveCardPokerEvaluator(5);

        fiveCardPokerEvaluator.setNumberOfHandsToPlay(649739);

        //play 100,000 (default number of hands) hands and track the statistics, then print the results to the screen
        fiveCardPokerEvaluator.playAndDisplay();

        //7 card evaluator
        //create a poker evaluator for 7 card poker
        //PokerEvaluator sevenCardPokerEvaluator(7);

        //set the number of hands to play- one million this time
        //sevenCardPokerEvaluator.setNumberOfHandsToPlay(1000);

        //add some user defined cards to the hand (these will be a part of every single one of the 1M hands)
        //sevenCardPokerEvaluator.addCardToHand(2, HEARTS);
        //sevenCardPokerEvaluator.addCardToHand(7, DIAMONDS);

        //play all the hands and track the statistics, then print the results to the screen
        //sevenCardPokerEvaluator.playAndDisplay();

        return 0;
    
}
