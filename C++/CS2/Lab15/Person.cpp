#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

Person::Person(string f, string l) {

	p_first = new string;
	p_last = new string;

	*p_first = f;
	*p_last = l;

	p_updatedLast = 0;

}

Person::~Person() {



}

void Person::updateLastName(string newLast) {
	if (p_updatedLast == 0) {

		p_updatedLast = new string;

	}

	*p_updatedLast = newLast;

}

string Person::getFirst() {

	return *p_first;

}

string Person::getOriginalLast() {

	return *p_last;

}

string Person::getLast() {

	if (p_updatedLast == 0) {

		return *p_last;

	}
	else {

		return *p_updatedLast;
	}

}