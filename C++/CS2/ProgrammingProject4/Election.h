#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Candidate.h"

using namespace std;

class Election
{
public:
	Election();
	Election(int totalVoters, vector <Candidate> candidates);
	void addCandidate(Candidate newCandidate);
	void runElection();
	
private:
	int numVoters;
	int choiceNum;
	void determineWinner();
	void showCandidates();
	void handleRunoff(vector <Candidate> tiedCandidates);
	vector <Candidate> canVec;

};

