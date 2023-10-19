#pragma once

#include <iostream>
#include <string>

using namespace std;

class BoggleDie
{
public:
	BoggleDie();
	BoggleDie(string faceVal);
	string getValue();
	void setValue(string faceVal);
	void setTraverse(bool t);
	bool getTraverse();
private:
	string faceValue;
	bool isTraversed;
};

