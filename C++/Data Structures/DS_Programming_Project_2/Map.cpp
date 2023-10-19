#include "Map.h"
#include <math.h>
#include <fstream>

using namespace std;

Map::Map(string filePath) {

	int sum = 0;
	int i = 0;
	string line;
	char c;

	//take first line of file and count the number of char in it
	ifstream infile;

	infile.open(filePath);

	if (infile.good())
	{

		getline(infile, line);

	}
	else
	{
		cout << "Cannot open the file: " << filePath << endl;
	}

	infile.close();

	for (int i = 0; i < line.length(); i++) {

		if (line.at(i) != ' ') {

			sum++;

		}

	}

	mapDimension = sum * sum;

	p_cells = new Cell*[mapDimension];

	for (int i = 0; i < mapDimension; i++) {

		p_cells[i] = new Cell;

	}

	infile.open(filePath);

	if (infile.is_open())
	{

		for(int i = 0; i < mapDimension; i++){


			infile >> c;
			p_cells[i]->setType(c);
			
		}

		infile.close();

	}
	else
	{
		cout << "Cannot open the file: " << filePath << endl;
	}

	//check for typecasting**
	mapDimension = sqrt(mapDimension);
	//p_cells is an arr of cell pointers after looping through the file, set cellType in this loop

	for (int i = 0; i < (sum * sum); i++) {

		int x = i % mapDimension;
		int y = i / mapDimension;

		
		p_cells[i]->setY(y);
		p_cells[i]->setX(x);

		if (p_cells[i]->getY() > 0) {

			p_cells[i]->setNorth(p_cells[i - mapDimension]);

		}
		else {

			p_cells[i]->setNorth(0);

		}

		if (p_cells[i]->getY() < (mapDimension - 1)) {

			p_cells[i]->setSouth(p_cells[i + mapDimension]);

		}
		else {

			p_cells[i]->setSouth(0);

		}

		if (p_cells[i]->getX() > 0) {

			p_cells[i]->setWest(p_cells[i - 1]);

		}
		else {

			p_cells[i]->setWest(0);

		}

		if (p_cells[i]->getX() < (mapDimension - 1)) {

			p_cells[i]->setEast(p_cells[i + 1]);

		}
		else {

			p_cells[i]->setEast(0);

		}

		

	}

}
Map::~Map() {

	//delete[] p_cells;
	//p_cells = 0;

}

int Map::getDimension() {

	return mapDimension;

}

void Map::printCells() {

	for (int i = 0; i < (mapDimension * mapDimension); i++) {

		cout << p_cells[i]->getType() << " ";

		if (i % mapDimension == mapDimension - 1) {

			cout << "\n";

		}

	}

}

Cell* Map::getStart() {

	Cell* empty = new Cell;

	for (int i = 0; i < mapDimension * mapDimension; i++) {

		if (p_cells[i]->getType() == 'S') {

			return p_cells[i];

		}


	}

	return empty;


}

Cell** Map::getCells() {

	return p_cells;

}