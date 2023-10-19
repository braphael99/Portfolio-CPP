#include <iostream>
#include <string>

using namespace std;

void printNums(int* p_nums, int length);
void separateEvensAndOdds(int* p_allNums, int length, int*& p_evens, int& evenCount, int*& p_odds, int& oddCOunt);

//the number of fibonacci numbers
const int NUM_FIBS = 10;

int main()
{
    //create a string on the heap and put your name in it
    //then print the name and its length using the string pointer
    string* p_name;
    p_name = new string;

    *p_name = "Blake";

    cout << "Name: " << *p_name << "Length: " << p_name->length() << "\n";

    //create an int on the heap and put your age it it
    //then print it out using the int pointer
    int* p_age = new int(19);

    cout << "Age: " << *p_age << "\n";

    //create an array of NUM_FIBS integers
    int* p_fibs = new int[NUM_FIBS];

    //fill the first two elements with 0 and 1 and then fill the rest

    p_fibs[0] = 0;
    p_fibs[1] = 1;

    for (int i = 2; i < NUM_FIBS; i++) {

        p_fibs[i] = p_fibs[i - 1] + p_fibs[i - 2];

    }

    //print the fibs
    cout << "Fibs up to " << NUM_FIBS << endl;
    printNums(p_fibs, NUM_FIBS);
    cout << endl;

    //used to separate the evens and odds
    int* p_fibEvens;
    int fibEvenCount;

    int* p_fibOdds;
    int fibOddCount;

    //make two new int arrays on the heap- one for evens and one for odds
    separateEvensAndOdds(p_fibs, NUM_FIBS, p_fibEvens, fibEvenCount, p_fibOdds, fibOddCount);

    //print the evens and the odds
    cout << "Fib Evens" << endl;
    printNums(p_fibEvens, fibEvenCount);
    cout << endl;

    cout << "Fib Odds" << endl;
    printNums(p_fibOdds, fibOddCount);
    cout << endl;

    //delete all data from the heap
    delete p_age;
    p_age = 0;
    
    delete[] p_fibEvens;
    p_fibEvens = 0;

    delete[] p_fibOdds;
    p_fibOdds = 0;

    delete[] p_fibs;
    p_fibs = 0;

    delete p_name;
    p_name = 0;

    return 0;
}
//--
void printNums(int* p_nums, int length)
{
    //print all of the numbers next to each other on the same line
    for (int i = 0; i < length; i++) {

        cout << p_nums[i] << " ";

    }
}
//--
void separateEvensAndOdds(int* p_allNums, int length, int*& p_evens, int& evenCount, int*& p_odds, int& oddCount)
{
    //go through the passed in numbers in p_allNums and count the evens and odds
    evenCount = 0;
    oddCount = 0;

    for (int i = 0; i < length; i++) {

        if (p_allNums[i] % 2 == 0) {

            evenCount++;

        }
        else {

            oddCount++;

        }

    }
    //then create two new arrays on the heap, one for evens and the other for odds
    p_evens = new int[evenCount];
    p_odds = new int[oddCount];
    //split the evens and odds into the two new arrays


    int evenIndex = 0;
    int oddIndex = 0;

  
    for (int i = 0; i < length; i++) {

        if (p_allNums[i] % 2 == 0) {

            p_evens[evenIndex] = p_allNums[i];
            evenIndex++;
        }
        else {

            p_odds[oddIndex] = p_allNums[i];
            oddIndex++;

        }

    }


}
