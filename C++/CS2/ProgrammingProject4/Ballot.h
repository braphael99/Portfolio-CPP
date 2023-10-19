#pragma once

#include "Candidate.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Ballot
{
public:
	Ballot();
private:
	vector <Candidate> candidates; //pointers
	Candidate choice;
};

