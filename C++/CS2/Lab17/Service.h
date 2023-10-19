#pragma once

#include "MonthlyBill.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Service : public MonthlyBill
{
public:
	Service(string name, string incCompanyName, string address, string accountNum, double incMonthlyRate);
	double getMonthlyPayment();
	void printReport(int numOfMonths);
private:
	double monthlyRate;
};

