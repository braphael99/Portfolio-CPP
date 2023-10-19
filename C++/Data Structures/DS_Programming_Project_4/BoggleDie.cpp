#include "BoggleDie.h"
#include <iostream>
#include <string>

using namespace std;

BoggleDie::BoggleDie() {

	faceValue = "";
	isTraversed = false;

}

BoggleDie::BoggleDie(string faceVal) {

	faceValue = faceVal;

}

string BoggleDie::getValue() {


	return faceValue;

}

void BoggleDie::setValue(string faceVal) {

	faceValue = faceVal;

}

void BoggleDie::setTraverse(bool t) {

	isTraversed = t;

}
bool BoggleDie::getTraverse() {

	return isTraversed;

}