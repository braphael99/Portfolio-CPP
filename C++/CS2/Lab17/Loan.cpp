#include "Loan.h"
#include "MonthlyBill.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Loan::Loan(string name, string incCompanyName, string address, string accountNum, double principleAmount, double annualInterestRate, int totalMonths)
: MonthlyBill(name, incCompanyName, address, accountNum) {

	principle = principleAmount;
	interestRate = annualInterestRate;
	remainingMonths = totalMonths;

	monthlyInterestRate = (annualInterestRate / 12) / 100;

}
double Loan::getMonthlyPayment() {

	double monthlyPayment;

	monthlyPayment = monthlyInterestRate / (1 - pow(1 + monthlyInterestRate, -remainingMonths)) * principle;

	return monthlyPayment;
	

}
void Loan::printReport(int numOfMonths) {

	double monthlyPayment = getMonthlyPayment();
	double interestPaid = principle * monthlyInterestRate * numOfMonths;
	double totalPaid = monthlyPayment * numOfMonths;
	double principleRemaining = principle - (totalPaid - interestPaid);

	cout << "Company: " << getCompanyName() << "\n";
	cout << "Friendly Name: " << getFriendlyName() << "\n";
	cout << "Account Number: " << getAccountNumber() << "\n";
	cout << "--- --- ---\n";

	cout << "Loan summary for " << numOfMonths << " months:\n";
	cout << "Monthly payment: " << monthlyPayment << "\n";
	cout << "Principle amount: " << principle << "\n";
	cout << "Annual interest rate: " << interestRate << "\n";
	cout << "Total number of months: " << remainingMonths << "\n";
	cout << "Principle remaining: " << principleRemaining << "\n";
	cout << "Interest paid: " << interestPaid << "\n";
	cout << "Total paid: " << totalPaid << "\n\n";

}