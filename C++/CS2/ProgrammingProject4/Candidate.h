#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Candidate
{
public:
	Candidate();
	Candidate(string fName, string lName, string party);
	void increaseVotes();
	int getVotes();
	string getName();
	string getAffiliation();
	void setWinner();
	int getWinner();
	void resetWinner();
	
	
private:
	string firstName;
	string lastName;
	string affiliation;
	int numVotes;
	int winnerFlag; 

};

