#include "Candidate.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Candidate::Candidate() {

	firstName = "";
	lastName = "";
	affiliation = "";
	numVotes = 0;
	winnerFlag = -1;

}

Candidate::Candidate(string fName, string lName, string party) {

	firstName = fName;
	lastName = lName;
	affiliation = party;
	numVotes = 0;
	winnerFlag = -1;

}

void Candidate::increaseVotes() {

	numVotes++;;

}

int Candidate::getVotes() {

	return numVotes;

}

string Candidate::getName() {

	return firstName + " " + lastName;

}

string Candidate::getAffiliation() {

	return affiliation;

}

void Candidate::setWinner() {

	winnerFlag = 1;

}

int Candidate::getWinner() {

	return winnerFlag;

}

void Candidate::resetWinner() {

	winnerFlag = -1;

}
