#pragma once
#include "Hunter.h"
#include "Treasure.h"
class GameEngine
{
public:
	//Constructors and destructors
	GameEngine();
	GameEngine(const char*);
	~GameEngine();
	//Methods
	ostream& printMap(ostream& out);
	ostream& printHunters(ostream& out);
	ostream& printTreasures(ostream& out);
	void play();
	void printMap();
private:
	enum DIRECTIONS{UP_LEFT, UP, UP_RIGHT, RIGHT, RIGHT_DOWN, DOWN, DOWN_LEFT, LEFT};
	Map *map;
	Hunter hunters[4];
	Treasure treasures[3];
	void placeHunters();
	void placeTreasures();
	void moveHunters();
	void moveHunter(Hunter &);
	pair<int, int>generateRandomPosition(vector<pair<int, int> >&generatedPositions);
};

