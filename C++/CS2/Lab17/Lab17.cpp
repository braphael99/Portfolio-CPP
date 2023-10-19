// Lab17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BillPortfolio.h"
#include <cmath>
#include <vector>
#include "MonthlyBill.h"
#include "Loan.h"
#include "Service.h"

using namespace std;

int main()
{
	BillPortfolio portfolio;

	MonthlyBill* p_mortgage = new Loan("Mark's Mortgage", "ABC Lenders", "123 Munney St", "123456", 100000, 12.00, 360);
	MonthlyBill* p_carLoan = new Loan("Tesla", "T Financing", "234 E Drive, LA CA", "345-56", 50000, 24.00, 120);
	MonthlyBill* p_cable = new Service("Cable", "AT&T", "345 TV Street, NY NY", "abc-123", 128.56);

	portfolio.addMonthlyBill(p_mortgage);
	portfolio.addMonthlyBill(p_carLoan);
	portfolio.addMonthlyBill(p_cable);

	double totalMonthlyPayment = portfolio.getTotalMonthlyBillAmount();
	cout << "Total payment: " << totalMonthlyPayment << "\n\n";

	portfolio.printAllReports(24);

	return 0;

}

