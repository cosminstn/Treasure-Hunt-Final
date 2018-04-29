#include "stdafx.h"
#include "GameEngine.h"
#include <fstream>
#include <iostream>
GameEngine::GameEngine()
{
}

GameEngine::GameEngine(char* conf) {
	ifstream gameConfig("GameConfig.init");
	if (gameConfig.good()) {
		//if the file has been opened successfully
		//read the dimensions of the map
		int w, h;
		gameConfig >> w >> h;
		cout << "W : " << w << " H : " << h;
		//the map must be at least 15 x 15
		if (this->mapWidth < 15)
			this->mapWidth = 15;
		if (this->mapHeight < 15)
			this->mapHeight = 15;
		//read the name of the hunters
		for (int i = 0; i < 4; i++) {
			gameConfig >> hunters[i];
		}
		this->initializeMap(this->mapWidth, this->mapHeight, '-');
		placeHunters();
	}
	else {
		cout << "\nErr : Could not open " << conf;
	}
	gameConfig.close();
}

void GameEngine::initializeMap(int width, int height, char allAroundValue) {
	//creates a width by height matrix filled with 'allAroundValue'
	//height = nr of rows
	//width = nr of cells
	this->mapWidth = width;
	this->mapHeight = height;
	this->map = new char*[height + 1];
	for (int i = 0; i <= height; i++) {
		map[i] = new char[width + 1];
	}
	for (int i = 0; i <= height; i++)
		for (int j = 0; j <= width; j++)
			map[i][j] = allAroundValue;
	this->placeHunters();
}

void GameEngine::placeHunters() {
	//first hunter on line 1 column 1
	hunters[0].moveTo(1, 1, this->map);
	//second hunter on line 1 column mapWidth
	hunters[1].moveTo(1, this->mapWidth, this->map);
	//third hunter on line mapHeight column mapWidth
	hunters[2].moveTo(this->mapHeight, this->mapWidth, this->map);
	//fourth hunter on line mapHeight column 1
	hunters[3].moveTo(this->mapHeight, 1, this->map);
}


ostream& GameEngine::printMap(ostream& out) {
	out << "\nMap right now : \n";
	for (int i = 1; i <= this->mapHeight; i++) {
		for (int j = 1; j <= this->mapWidth; j++)
			out << map[i][j];
		out << '\n';
	}
	return out;
}

void GameEngine::printHunters() {
	for (int i = 0; i < 4; i++)
		cout << hunters[i] << '\n';
}



GameEngine::~GameEngine()
{
}
