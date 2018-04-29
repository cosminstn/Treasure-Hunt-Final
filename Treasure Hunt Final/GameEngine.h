#pragma once
#include "Hunter.h"
#include "Treasure.h"
class GameEngine
{
public:
	//Constructors and destructors
	GameEngine();
	GameEngine(char*);
	~GameEngine();
	//Methods
	ostream& printMap(ostream& out);
private:
	char **map;
	int mapWidth, mapHeight;
	void initializeMap(int, int, char);
	
	Hunter hunters[4];
	void placeHunters();
	void printHunters();
};

