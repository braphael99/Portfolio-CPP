// ProgrammingProject4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Election.h"
#include <iostream>
#include <string>
#include <vector>
#include "Candidate.h"

using namespace std;

int main()
{

    vector <Candidate> electionCandidates;

    Candidate c1("Jerry", "Smith", "Red Party");
    Candidate c2("Rob", "Jones", "Blue Party");
    Candidate c3("John", "Johnson", "Yellow Party");
    Candidate c4("Toby", "Wright", "Green Party");

    electionCandidates.push_back(c1);
    electionCandidates.push_back(c2);
    electionCandidates.push_back(c3);
    electionCandidates.push_back(c4);

    Election election(15, electionCandidates);

    election.runElection();


    return 0;
}
