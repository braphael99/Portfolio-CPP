#include "Cell.h"

Cell::Cell() {

	x = -1;
	y = -1;
	p_north = 0;
	p_south = 0;
	p_east = 0;
	p_west = 0;
	isTraversed = false;
	onDeadPath = false;

}

Cell::~Cell() {

	delete p_north;
	p_north = 0;

	delete p_south;
	p_south = 0;

	delete p_east;
	p_east = 0;

	delete p_west;
	p_west = 0;

}

 char Cell::getType() {

	return cellType;

}

void Cell::setType(char incType) {

	cellType = incType;

}

int Cell::getY() {

	return y;

}

void Cell::setY(int incY) {

	y = incY;

}

int Cell::getX() {

	return x;

}

void Cell::setX(int incX) {

	x = incX;

}

Cell* Cell::getNorth() {

	return p_north;

}

Cell* Cell::getSouth() {

	return p_south;

}

Cell* Cell::getEast() {

	return p_east;

}
Cell* Cell::getWest() {

	return p_west;

}

void Cell::setWest(Cell* p_incCell) {

	p_west = p_incCell;

}

void Cell::setNorth(Cell* p_incCell) {

	p_north = p_incCell;

}

void Cell::setSouth(Cell* p_incCell) {

	p_south = p_incCell;

}

void Cell::setEast(Cell* p_incCell) {

	p_east = p_incCell;

}

bool Cell::getTraversedStatus() {

	return isTraversed;

}

void Cell::setTraversed(bool incBool) {

	isTraversed = incBool;

}

bool Cell::checkDeadPath() {

	return onDeadPath;

}

void Cell::setDeadPath() {

	onDeadPath = true;

}