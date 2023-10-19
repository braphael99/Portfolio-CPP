#include "Service.h"
#include "MonthlyBill.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Service::Service(string name, string incCompanyName, string address, string accountNum, double incMonthlyRate)
: MonthlyBill(name, incCompanyName, address, accountNum){

	monthlyRate = incMonthlyRate;

}
double Service::getMonthlyPayment() {

	return monthlyRate;

}
void Service::printReport(int numOfMonths) {

	double monthlyPayment = getMonthlyPayment();

	cout << "Company: " << getCompanyName() << "\n";
	cout << "Friendly Name: " << getFriendlyName() << "\n";
	cout << "Account Number: " << getAccountNumber() << "\n";
	cout << "--- --- ---\n";

	cout << "Service summary for " << numOfMonths << " months:\n";
	cout << "Monthly payment: " << monthlyPayment << "\n";
	cout << "Total paid: " << monthlyPayment * numOfMonths << "\n\n";

}