#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Map
{
public:
	//Constructors and destructors
	Map();
	Map(int , int , char);
	~Map();
	int getWidth();
	int getHeight();
	char getItemAtLocation(int, int);
	void setItemAtLocation(int, int, char);
	void clearLocation(int, int);
	bool isLocationVirgin(int, int);
	void printMap();
	vector<pair<int, int>> getSurroundingVirginBlocks(int, int);
	int getNrOfTreasuresLeft();
private:
	char **map, initializer, visitedPlace = '.', nullPlace = ' ';
	int width, height, treasuresLeft;

};

