#pragma once
#include <string>
#include <iostream>
#include "Cell.h"
#include <fstream>

using namespace std;

class Map
{
public:
	Map(string filePath);
	~Map();
	void printCells();
	int getDimension();
	Cell* getStart();
	Cell** getCells();
private:
	Cell** p_cells;
	int mapDimension;
};

