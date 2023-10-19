#include "SafeArrayInt.h"
#include <iostream>
#include <string>

using namespace std;

SafeArrayInt::SafeArrayInt() {

	p_numsArr = new int[10];
	arrUsage = 0;
	capacity = 10;

}

SafeArrayInt::~SafeArrayInt() {

	delete[]p_numsArr;

	p_numsArr = 0;

}

void SafeArrayInt::push_back(int newVal) {

	if (arrUsage < capacity) {

		*(p_numsArr + arrUsage) = newVal;
		arrUsage++;

	}
	else {

		doubleArray();
		*(p_numsArr + arrUsage) = newVal;
		arrUsage++;

	}

}

int SafeArrayInt::pop_back() {



}

int& SafeArrayInt::at(int pos) {

	return p_numsArr[pos];

}

int SafeArrayInt::size() {

	return arrUsage;

}

int& SafeArrayInt::operator[](int pos) {

	return at(pos);

}

void SafeArrayInt::doubleArray() {

	int originalCap = capacity;

	capacity = capacity * 2;

	int* p_temp = new int[capacity];

	for (int i = 0; i < originalCap; i++) {

		p_temp[i] = p_numsArr[i];

	}

	delete[] p_numsArr;

	p_numsArr = p_temp;

	p_temp = 0;

}

void SafeArrayInt::halfArray() {

	capacity = capacity / 2;

	int* p_temp = new int[capacity];

	for (int i = 0; i < arrUsage; i++) {

		p_temp[i] = p_numsArr[i];

	}

	delete[] p_numsArr;

	p_numsArr = p_temp;

	p_temp = 0;

}