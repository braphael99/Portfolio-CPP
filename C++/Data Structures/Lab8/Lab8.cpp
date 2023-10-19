// Lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void countDown(int n);
void countUp(int n);
int power(int base, int exponent);
int powerHelper(int base, int currVal, int exp);
void printInBinary(int num);

int main()
{
    countDown(5); //5 4 3 2 1
    cout << endl;

    countUp(5); //1 2 3 4 5
    cout << endl;

    cout << power(2, 10) << endl; //1024

    //0 - 9 in binary is 0 - 1001
    for (int i = 0; i < 10; i++)
    {
        cout << i << " is equal to ";
        printInBinary(i);
        cout << " in binary" << endl;
    } 

    printInBinary(1023); //1111111111
    cout << endl;
    printInBinary(1024); //10000000000
    cout << endl;
    printInBinary(1025); //10000000001
    cout << endl;

    return 0;
}
//--
void countDown(int n)
{
    if (n == 1) {

        cout << n << "\n";

    }
    else {

        cout << n << "\n";
        countDown(n - 1);

    }
}
//--
void countUp(int n)
{
    
    if (n > 1) {

        countUp(n - 1);

    }
    cout << n << "\n";

}
//--
int power(int base, int exponent)
{
    return powerHelper(base, 1, exponent);
}

int powerHelper(int base, int currVal, int exp) {

    if (exp == 0) {

        return currVal;

    }
    else {
        currVal = base * currVal;
        return powerHelper(base, currVal, exp - 1);

    }

}
//--
void printInBinary(int num)
{
    int rem = num % 2;
    int quot = num / 2;

    if (quot > 0) {

        printInBinary(quot);

    }
    cout << rem;

}