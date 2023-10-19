#include "Tracker.h"

Tracker::Tracker() {

	mapDimension = 0;

}

Tracker::~Tracker() {



}
void Tracker::findPath(Map map) {

	mapDimension = map.getDimension();

	p_allCells = map.getCells();

	Cell* currCell = map.getStart();

	currCell->setTraversed(true);

	while (currCell->getType() != 'E') {

		//go to N pointer then check type, if free add to stack, if blocked or traversed then go to
		//next if statement, how to check next cell type?
		if (currCell->getNorth() != 0 && currCell->getNorth()->getType() != 'B' && currCell->getNorth()->getTraversedStatus() != true && currCell->getNorth()->checkDeadPath() != true) {

			cellStack.push(currCell);
			currCell = currCell->getNorth();
			currCell->setTraversed(true);

			cout << "Going North X: " << currCell->getX() << " Y: " << currCell->getY() << " Type: " << currCell->getType() << "\n";
			

		}
		else if (currCell->getSouth() != 0 && currCell->getSouth()->getType() != 'B' && currCell->getSouth()->getTraversedStatus() != true && currCell->getSouth()->checkDeadPath() != true) {

			cellStack.push(currCell);
			currCell = currCell->getSouth();
			currCell->setTraversed(true);
			
			cout << "Going South X: " << currCell->getX() << " Y: " << currCell->getY() << " Type: " << currCell->getType() << "\n";

		}
		else if (currCell->getEast() != 0 && currCell->getEast()->getType() != 'B' && currCell->getEast()->getTraversedStatus() != true && currCell->getEast()->checkDeadPath() != true) {

			currCell = currCell->getEast();
			currCell->setTraversed(true);
			cellStack.push(currCell);

			cout << "Going East X: " << currCell->getX() << " Y: " << currCell->getY() << " Type: " << currCell->getType() << "\n";

		}
		else if (currCell->getWest() != 0 && currCell->getWest()->getType() != 'B' && currCell->getWest()->getTraversedStatus() != true && currCell->getWest()->checkDeadPath() != true) {

			cellStack.push(currCell);
			currCell = currCell->getWest();
			currCell->setTraversed(true);
			
			cout << "Going West X: " << currCell->getX() << " Y: " << currCell->getY() << " Type: " << currCell->getType() << "\n";

		}
		else {

			cout << "Backtracking from X: " << currCell->getX() << " Y: " << currCell->getY() << " Type: " << currCell->getType() <<
				" to X: " << cellStack.top()->getX() << " Y: " << cellStack.top()->getY() << " Type: " << cellStack.top()->getType() << "\n";

			currCell->setDeadPath();
			currCell->setTraversed(false);
			currCell = cellStack.top();
			cellStack.pop();
			

		}

		}
		

	}

	//start at start cell and add to stack, check N E S W, mark as traversed
	//if blocked on three sides (i.e. traversed or B) then "back track" by popping off stack
	//but keep as traversed until we find a correct path. If we pop off stack, make sure to mark as on a dead path
	//so we do not get stuck in a loop

void Tracker::printRoute() {

	for (int i = 0; i < mapDimension * mapDimension; i++) {

		if (p_allCells[i]->checkDeadPath() == true || p_allCells[i]->getType() == 'B' || p_allCells[i]->getTraversedStatus() == false) {

			cout << "X ";

		}
		else {

			cout << "O ";

		}

		if (i % mapDimension == mapDimension - 1) {

			cout << "\n";

		}

	}

}