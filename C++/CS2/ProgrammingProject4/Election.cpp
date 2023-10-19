#include "Election.h"
#include <iostream>
#include <string>
#include <vector>
#include "Candidate.h"

using namespace std;

Election::Election() {

	numVoters = 0;
	choiceNum = -1;

}

Election::Election(int totalVoters, vector <Candidate> candidates) {

	numVoters = totalVoters;
	choiceNum = -1;

	for (int i = 0; i < candidates.size(); i++) {

		canVec.push_back(candidates[i]);

	}

}

void Election::addCandidate(Candidate newCandidate) {

	canVec.push_back(newCandidate);

}

void Election::runElection() {

	for(int i = 0; i < numVoters; i++){
		
		cout << "\nVoter " << i + 1 << ", please enter the number that corresponds to the candidate of your choice: \n";
		showCandidates();

		cin >> choiceNum;
		choiceNum--;

		canVec[choiceNum].increaseVotes();


	}

	determineWinner();

}

void Election::determineWinner() {

	int maxVotes = 0;
	int numTiedCandidates = 0;
	int winnerMarker = -1;
	vector <Candidate> tiedWinners;
	Candidate winner;

	for (int i = 0; i < canVec.size(); i++) {

		canVec[i].resetWinner();

		if (canVec[i].getVotes() > maxVotes) {

			maxVotes = canVec[i].getVotes();

		}

	}

	for (int i = 0; i < canVec.size(); i++) {

		if (canVec[i].getVotes() == maxVotes) {

			numTiedCandidates++;
			tiedWinners.push_back(canVec[i]);
			canVec[i].setWinner();

		}

	}

	if (numTiedCandidates > 1) {

		for (int i = 0; i < canVec.size(); i++) {

			if (canVec[i].getWinner() == 1) {

				cout << "*" << canVec[i].getName() << "\nParty: " << canVec[i].getAffiliation() << "\nVotes: " << canVec[i].getVotes() << "\n\n";

			}
			else {

				cout << canVec[i].getName() << "\nParty: " << canVec[i].getAffiliation() << "\nVotes: " << canVec[i].getVotes() << "\n\n";

			}

		}

			handleRunoff(tiedWinners);

		
	}
	else {

		for (int i = 0; i < canVec.size(); i++) {

			if (canVec[i].getWinner() == 1) {

				cout << "*" << canVec[i].getName() << "\nParty: " << canVec[i].getAffiliation() << "\nVotes: " << canVec[i].getVotes() << "\n\n";

			}
			else {

				cout << canVec[i].getName() << "\nParty: " << canVec[i].getAffiliation() << "\nVotes: " << canVec[i].getVotes() << "\n\n";

			}

		}

	}

}

void Election::showCandidates() {

	for (int i = 0; i < canVec.size(); i++) {

		cout << "Candidate " << i + 1 << ": ";
		cout << canVec[i].getName() << "\n";
		cout << canVec[i].getAffiliation() << "\n\n";

	}

}

void Election::handleRunoff(vector <Candidate> tiedCandidates)
{
	Election* p_runOff = new Election(numVoters, tiedCandidates);

	p_runOff->runElection();
		
	delete p_runOff;
}