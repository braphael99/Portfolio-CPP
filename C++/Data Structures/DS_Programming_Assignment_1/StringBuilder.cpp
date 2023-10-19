#include "StringBuilder.h"
#include <iostream>
#include <string>

using namespace std;

StringBuilder::StringBuilder() {

	p_stringArr  = new string[10];
	arrUsage = 0;
	capacity = 10;

}

StringBuilder::~StringBuilder() {

	delete[] p_stringArr;

	p_stringArr = 0;

}

void StringBuilder::append(string strToAdd) {

	if (arrUsage < capacity) {

		p_stringArr[arrUsage] = strToAdd;
		

	}
	else {

		doubleArray();
		p_stringArr[arrUsage] = strToAdd;
		

	}

	arrUsage++;

}

void StringBuilder::insert(int pos, string strToAdd) {


	for (int i = arrUsage; i > pos; i--) {

		if (arrUsage = capacity - 2) {

			doubleArray();
			p_stringArr[i] = p_stringArr[i + 1];

		}
		else {

			p_stringArr[i] = p_stringArr[i + 1];

		}

	}

	p_stringArr[pos] = strToAdd;

	arrUsage++;

}

void StringBuilder::appendAll(string* strArr, int arrLength) {

	for (int i = 0; i < arrLength; i++) {

		if (arrUsage < capacity) {

			p_stringArr[arrUsage] = strArr[i];
			arrUsage++;

		}
		else {

			doubleArray();
			p_stringArr[arrUsage] = strArr[i];
			arrUsage++;

		}

	}

}

int StringBuilder::length() {

	return arrUsage;

}

void StringBuilder::clear() {

	delete[] p_stringArr;

	p_stringArr = new string[10];

	arrUsage = 0;

}

void StringBuilder::removeAll(string strToDel) {

	string* p_currArr = new string;

	p_currArr = getString();

	string currentArray = *p_currArr;

	while (currentArray.find(strToDel) < currentArray.length()) {
		string::size_type i = currentArray.find(strToDel);

		if (i != string::npos)
		{
			currentArray.erase(i, strToDel.length());
		}
	}

	clear();

	*p_currArr = currentArray;

	append(*p_currArr);

	delete p_currArr;

	p_currArr = 0;

}

string* StringBuilder::getString() {

	int sum = 0;
	int charArrPos = 0;


	for (int i = 0; i < arrUsage; i++) {

		sum += p_stringArr[i].length();

	}

	char* charArr = new char[sum];

	for (int i = 0; i < arrUsage; i++) {

		for (int j = 0; j < int(p_stringArr[i].length()); j++) {

			charArr[charArrPos] = p_stringArr[i].at(j);
			charArrPos++;

		}

	}

	string* p_strToReturn = new string(charArr, sum);

	delete[] charArr;

	charArr = 0;

	return p_strToReturn;

}

void StringBuilder::doubleArray() {

	int originalCap = capacity;

	capacity = capacity * 2;

	string* p_temp = new string[capacity];

	for (int i = 0; i < originalCap; i++) {

		p_temp[i] = p_stringArr[i];

	}

	delete[] p_stringArr;

	p_stringArr = p_temp;

	delete[] p_temp;

	p_temp = 0;

}