#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class MonthlyBill
{
public:
	MonthlyBill();
	MonthlyBill(string name, string incCompanyName, string address, string accountNum);
	virtual double getMonthlyPayment() = 0;
	virtual void printReport(int numOfMonths) = 0;
	string getFriendlyName();
	string getCompanyName();
	string getBillingAddress();
	string getAccountNumber();

private:
	string friendlyName;
	string companyName;
	string billingAddress;
	string accountNumber;

};

