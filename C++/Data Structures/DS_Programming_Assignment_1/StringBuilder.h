#pragma once
#include <iostream>
#include <string>

using namespace std;

class StringBuilder
{
public:
	StringBuilder();
	~StringBuilder();

	void append(string strToAdd);
	void insert(int pos, string strToAdd);
	void appendAll(string* strArr, int arrLength);
	int length();
	void clear();
	void removeAll(string strToDel);
	string* getString();

private:

	string* p_stringArr;
	int arrUsage;
	int capacity;
	void doubleArray();


};

