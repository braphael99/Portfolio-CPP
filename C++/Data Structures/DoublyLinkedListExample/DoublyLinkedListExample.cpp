// DoublyLinkedListExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

#include "DoublyLinkedList.h"

using namespace std;

void verifyLinksInBothDirections(DoublyLinkedList < int >& list);
void randomNumbersInsert();
void randomNumbersRemove();
void randomNumbersInsertAndRemove();
void simpleList();

//some constants so that I can experiment with my tests
const int NUM_ITERATIONS = 10;
const int SCALE_FACTOR = 10;

int main()
{
    cout << "Doubly Linked List Driver" << endl;

    //use different random numbers each time
    srand(time(0));

    //use the same random numbers from one run to another
    //srand(0);

    //test very basic stuff
    simpleList();

    //really try and break it with random inserts and removes
    for (int i = 0; i < 100; i++)
    {
        cout << "iteration: " << (i + 1) << " " << endl;
        randomNumbersInsert();
        randomNumbersRemove();
        randomNumbersInsertAndRemove();
    }

    cout << "Done" << endl;
    return 0;
}
//--
void simpleList()
{
    //create a list
    DoublyLinkedList < int > list;

    //do some inserts
    list.insertAtRear(20);  //20
    list.insertAtFront(10); //10 20
    list.insertAtRear(30);  //10 20 30
    list.insertAtRear(25);  //10 20 30 25
    list.insertAtRear(5);   //10 20 30 25 5
    list.insertAtFront(20); //20 10 20 30 25 5
    list.insertAtRear(20);  //20 10 20 30 25 5 20
    list.insertAtRear(40);  //20 10 20 30 25 5 20 40
    list.insertAtFront(15); //15 20 10 20 30 25 5 20 40
    list.insertAtFront(5);  //5 15 20 10 20 30 25 5 20 40
    list.insertAtRear(40);  //5 15 20 10 20 30 25 5 20 40 40

    if (list.find(20) == false ||
        list.find(10) == false ||
        list.find(30) == false ||
        list.find(25) == false ||
        list.find(5) == false ||
        list.find(40) == false ||
        list.find(15) == false)
    {
        cout << "Problems with find()" << endl;
    }

    if (list.find(-20) == true ||
        list.find(-10) == true ||
        list.find(-30) == true ||
        list.find(-25) == true ||
        list.find(-5) == true ||
        list.find(-40) == true ||
        list.find(-15) == true)
    {
        cout << "Problems with find()" << endl;
    }

    //test the at() method
    if (list.at(9) != 40 ||
        list.at(0) != 5 ||
        list.at(3) != 10 ||
        list.at(2) != 20 ||
        list.at(4) != 20)
    {
        cout << "Problems with at()" << endl;
        cout << "list.at(9): " << list.at(9) << " should be: " << 40 << endl;
        cout << "list.at(0): " << list.at(0) << " should be: " << 5 << endl;
        cout << "list.at(3): " << list.at(3) << " should be: " << 10 << endl;
        cout << "list.at(2): " << list.at(2) << " should be: " << 20 << endl;
        cout << "list.at(4): " << list.at(4) << " should be: " << 20 << endl;
    }

    try
    {
        list.at(100);
        cout << "Problem with exception NOT being thrown" << endl;
    }
    catch (...) //catch any type of exception here
    {
        //do nothing, this should happen
    }


    //verify
    verifyLinksInBothDirections(list);

    //remove some elements
    list.remove(25); //5 15 20 10 20 30 5 20 40 40
    list.remove(5);  //15 20 10 20 30 20 40 40
    list.remove(20); //15 10 30 40 40
    list.remove(10); //15 30 40 40
    list.remove(40); //15 30

    //verify
    verifyLinksInBothDirections(list);

    //remove some elements
    list.remove(3000); //15 30
    list.remove(15); //30
    list.remove(30); //empty
    list.remove(100);//remove from an empty list

    //verify
    verifyLinksInBothDirections(list);

    list.insertAtFront(20); //20
    list.insertAtRear(10);  //20 10
    list.insertAtFront(30); //30 20 10
    list.insertAtFront(25); //25 30 20 10

    //verify
    verifyLinksInBothDirections(list);

    int x;
    list.removeFromFront(x); //30 20 10
    list.removeFromRear(x);  //30 20
    list.removeFromFront(x); //20
    list.removeFromRear(x);

    //verify
    verifyLinksInBothDirections(list);
}
//--
void verifyLinksInBothDirections(DoublyLinkedList < int >& list)
{
    //make sure we read all of the elements, count them and compare to the length
    int count = 0;

    //loop through all the elements
    int data;

    if (list.first(data))
    {
        //count the read
        count++;

        while (list.next(data))
        {
            //count the read
            count++;
        }
    }

    //make sure there were the same number of reads as elements
    if (count != list.size())
    {
        cout << "Forward direction problems" << endl;
    }

    //now go in reverse
    count = 0;

    if (list.last(data))
    {
        count++;

        while (list.previous(data))
        {
            count++;
        }
    }

    //check the count
    if (count != list.size())
    {
        cout << "Backward direction problems" << endl;
    }
}
//--
void randomNumbersInsert()
{
    //create a list
    DoublyLinkedList < int > list;

    //add random integers to it
    for (int i = 0; i < NUM_ITERATIONS; i++)
    {
        //pick a random number
        int num = rand();

        //if it is even
        if (num % 2 == 0)
        {
            //insert it at the front
            list.insertAtFront(num);
        }
        else //it is odd
        {
            //insert it at the rear
            list.insertAtRear(num);
        }

        //verify
        verifyLinksInBothDirections(list);
    }
}
//--
void randomNumbersRemove()
{
    //create a list
    DoublyLinkedList < int > list;

    //add some random numbers
    for (int i = 0; i < NUM_ITERATIONS; i++)
    {
        //scale down to numbers between 0-(SCALE_FACTOR-1)
        list.insertAtRear(rand() % SCALE_FACTOR);
    }

    int data;
    //go through all the elements and remove the evens
    if (list.first(data))
    {
        //if the number is even
        if (data % 2 == 0)
        {
            //remove it
            list.remove();
        }

        //go through the rest of the numbers and do the same
        while (list.next(data))
        {
            if (data % 2 == 0)
            {
                list.remove();
            }
        }

        //verify
        verifyLinksInBothDirections(list);
    }

    //while the list is not empty
    while (!list.isEmpty())
    {
        //attempt to remove a random number
        list.remove(rand() % SCALE_FACTOR);
    }

    //verify
    verifyLinksInBothDirections(list);
}
//--
void randomNumbersInsertAndRemove()
{
    //create a list
    DoublyLinkedList < int > list;

    //mix inserts and removes
    for (int i = 0; i < NUM_ITERATIONS; i++)
    {
        //flip a coin- insert
        if (rand() % 2 == 0)
        {
            //flip a coin
            if (rand() % 2 == 0)
            {
                //insert a random number at front
                list.insertAtFront(rand() % SCALE_FACTOR);
            }
            else
            {
                //insert a random number at rear
                list.insertAtRear(rand() % SCALE_FACTOR);
            }

            //verify
            verifyLinksInBothDirections(list);
        }
        else//flip a coin- remove
        {
            //attempt to remove a random number
            list.remove(rand() % SCALE_FACTOR);

            //verify
            verifyLinksInBothDirections(list);
        }
    }

    //while the list is not empty
    while (!list.isEmpty())
    {
        //attempt to remove a random number
        list.remove(rand() % SCALE_FACTOR);

        //verify
        verifyLinksInBothDirections(list);
    }
}