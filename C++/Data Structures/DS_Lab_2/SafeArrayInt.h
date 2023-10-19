#pragma once
class SafeArrayInt
{
public:
	SafeArrayInt();
	~SafeArrayInt();

	void push_back(int newVal);
	int pop_back();
	int& at(int pos);
	int size();
	int& operator[](int pos);
private:
	int* p_numsArr;
	int arrUsage;
	int capacity;
	void doubleArray();
	void halfArray();

};

