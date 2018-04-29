#pragma once
#include "Hunter.h"
#include "Treasure.h"
using namespace std;
class GameEngine
{
public:
	//Constructors and destructors
	GameEngine();
	GameEngine(const char*);
	~GameEngine();
	//Methods
	std::ostream& printMap(std::ostream& out);
	std::ostream& printHunters(std::ostream& out);
	std::ostream& printTreasures(std::ostream& out);
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
	int moveHunter(Hunter &);
	void printResults();
	pair<int, int>generateRandomPosition(vector<pair<int, int> >&generatedPositions);

};

