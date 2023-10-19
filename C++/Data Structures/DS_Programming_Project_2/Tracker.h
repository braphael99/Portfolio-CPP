#pragma once

#include "Map.h"
#include "Cell.h"
#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;
class Tracker
{
public:
	Tracker();
	~Tracker();
	void findPath(Map map);
	void printRoute();
private:
	int mapDimension;
	Stack <Cell*> cellStack;
	Cell** p_allCells;
};

