#pragma once
class Cell
{
public:
	Cell();
	~Cell();
	char getType();
	void setType(char incType);
	int getY();
	void setY(int incY);
	int getX();
	void setX(int incX);
	Cell* getNorth();
	Cell* getSouth();
	Cell* getEast();
	Cell* getWest();
	void setWest(Cell* p_incCell);
	void setNorth(Cell* p_incCell);
	void setSouth(Cell* p_incCell);
	void setEast(Cell* p_incCell);
	bool getTraversedStatus();
	void setTraversed(bool incBool);
	bool checkDeadPath();
	void setDeadPath();
private:
	int x;
	int y;
	char cellType;
	Cell* p_north;
	Cell* p_south;
	Cell* p_east;
	Cell* p_west;
	bool isTraversed;
	bool onDeadPath;
};

