#pragma once

#include "MonthlyBill.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Loan : public MonthlyBill
{
public:
	Loan(string name, string incCompanyName, string address, string accountNum, double principleAmount, double annualInterestRate, int totalMonths);
	double getMonthlyPayment();
	void printReport(int numOfMonths);
private:
	double principle;
	double interestRate;
	double monthlyInterestRate;
	int remainingMonths;
};

