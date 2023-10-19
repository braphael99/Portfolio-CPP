// DS_Programming_Project_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Cell.h"
#include "Map.h"
#include "Tracker.h"
#include <fstream>

using namespace std;

int main()
{
    //create a map from a file
    Map map("C:\\Users\\braph\\Desktop\\Portfolio\\C++\\Data Structures\\6x6map.txt");

    //create a tracker capable of traversing through a map
    Tracker tracker;

    //send the tracker to find a path through the map
    tracker.findPath(map);

    //print the original cells from the file
    map.printCells();

    //print an X/O map from the start to the end
    tracker.printRoute();

    return 0;
}

