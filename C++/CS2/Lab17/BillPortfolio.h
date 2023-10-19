#pragma once

#include <iostream>
#include <vector>
#include "MonthlyBill.h"
#include "Loan.h"
#include "Service.h"

using namespace std;

class BillPortfolio
{
public:
    BillPortfolio();
    ~BillPortfolio();
    void addMonthlyBill(MonthlyBill* newBill);
    double getTotalMonthlyBillAmount();
    void printAllReports(int numMonths);
private:
    vector < MonthlyBill* > allBills;
};

