#include "BillPortfolio.h"
#include <iostream>
#include <vector>
#include "MonthlyBill.h"
#include "Loan.h"
#include "Service.h"

using namespace std;

BillPortfolio::BillPortfolio() {



}
BillPortfolio::~BillPortfolio() {

	for (int i = 0; i < allBills.size(); i++) {

		delete allBills[i];

	}

}
void BillPortfolio::addMonthlyBill(MonthlyBill* newBill) {

	allBills.push_back(newBill);

}
double BillPortfolio::getTotalMonthlyBillAmount() {

	double totalMonthlyAmount = 0.0;

	for (int i = 0; i < allBills.size(); i++) {

		totalMonthlyAmount += allBills[i]->getMonthlyPayment();

	}

	return totalMonthlyAmount;

}
void BillPortfolio::printAllReports(int numMonths) {

	for (int i = 0; i < allBills.size(); i++) {

		allBills[i]->printReport(numMonths);

	}
}