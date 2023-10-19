#include "MonthlyBill.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

MonthlyBill::MonthlyBill() {

	friendlyName = "";
	companyName = "";
	billingAddress = "";
	accountNumber = -1;

}
MonthlyBill::MonthlyBill(string name, string incCompanyName, string address, string accountNum) {

	friendlyName = name;
	companyName = incCompanyName;
	billingAddress = address;
	accountNumber = accountNum;

}
string MonthlyBill::getFriendlyName() {

	return friendlyName;

}
string MonthlyBill::getCompanyName() {

	return companyName;

}
string MonthlyBill::getBillingAddress() {

	return billingAddress;

}
string MonthlyBill::getAccountNumber() {

	return accountNumber;

}