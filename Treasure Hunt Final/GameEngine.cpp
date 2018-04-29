#include "stdafx.h"
#include "GameEngine.h"
#include <fstream>
#include <time.h>
#include <string>
#include "Map.h"

GameEngine::GameEngine(){
	
}

GameEngine::GameEngine(const char* conf) {
	ifstream gameConfig;
	gameConfig.open(conf, ios::in);
	if (gameConfig.is_open()) {
		//not solved yet!! this does not work on reading from file
		//TODO : fix reading from file
		//if the file has been opened successfully
		//read the dimensions of the map
		map = new Map(15, 15, '-');
		hunters[0].setName("Vasco da Gama");
		hunters[1].setName("James Augustus Grant");
		hunters[2].setName("Hippalus");
		hunters[3].setName("John Knight");
		//read treasures
		treasures[0].setName("Gold");
		treasures[1].setName("Silver");
		treasures[2].setName("Booze");

		placeHunters();
		placeTreasures();
		printMap();
	}
	else {
		cout << "\nErr : Could not open " << conf;
	}
	gameConfig.close();
}

void GameEngine::printMap() {
	map->printMap();
}

void GameEngine::play() {
	moveHunters();
	printMap();
	printResults();
}

void GameEngine::placeHunters() {
	//first hunter on line 1 column 1
	hunters[0].moveTo(1, 1, (Map&) *map);
	hunters[0].setStatus(true);
	//second hunter on line 1 column mapWidth
	hunters[1].moveTo(1, map->getWidth(), (Map&) *map);
	hunters[1].setStatus(true);
	//third hunter on line mapHeight column mapWidth
	hunters[2].moveTo(map->getHeight(), map->getWidth(), (Map&) *map);
	hunters[2].setStatus(true);
	//fourth hunter on line mapHeight column 1
	hunters[3].moveTo(map->getHeight(), 1, (Map&) *map);
	hunters[3].setStatus(true);
}

void GameEngine::placeTreasures() {
	
	//all treasures must be places randomly
	//initialize random seed
	srand(time(NULL));
	
	vector<pair<int, int> >generatedPositions;
	//push all hunters positions in the generated positions vector so no treasure is generated over a hunter
	for (int i = 0; i < 4; i++) {
		generatedPositions.push_back(make_pair(hunters[i].getPosX(), hunters[i].getPosY()));
	}

	//generate x and y for each treasure
	for (int i = 0; i < 3; i++) {
		pair<int, int> cPair = generateRandomPosition(generatedPositions);
		treasures[i].moveTo(cPair.first, cPair.second, (Map&)* map);
	}
}

pair<int, int> GameEngine::generateRandomPosition(vector<pair<int, int>> &generatedPositions) {
	//call the function recursively until it finds a pair that hasn't already been generated
	int x = rand() % map->getWidth() + 1;
	int y = rand() % map->getHeight() + 1;
	pair<int, int> cPair = make_pair(y, x);
	for (int i = 0; i < generatedPositions.size(); i++) {
		if (cPair == generatedPositions[i] || !map->isLocationVirgin(cPair.first, cPair.second))
			return generateRandomPosition(generatedPositions);
	}
	generatedPositions.push_back(cPair);
	return cPair;
}

void GameEngine::moveHunters() {
	//moves the hunters advancing one round in the game
	int availableMoves = 1;
	while (map->getNrOfTreasuresLeft() > 0) {
		availableMoves = 0;
		for (int i = 0; i < 4; i++)
			if (hunters[i].getStatus()) //it means that the hunter is still searching for a treasure
				availableMoves += moveHunter((Hunter&)hunters[i]);
		printMap();
	}
}

int GameEngine::moveHunter(Hunter &hunter) {
	//get the 
	//get virgin locations surrounding the hunter
	vector<pair<int, int>> validLocations = map->getSurroundingVirginBlocks(hunter.getPosY(), hunter.getPosX());
	if (validLocations.size() > 0) {
		//choose a random direction
		srand(time(NULL));
		int dir = rand() % validLocations.size();
		hunter.moveTo(validLocations[dir].first, validLocations[dir].second, (Map &)*map);
	}
	else
		hunter.setStatus(false);	//stop looking if there are no left options for the hunter

	//returns the number of available moves for the specified hunter
	return validLocations.size();
}

//print each hunter with the treasure he found
void GameEngine::printResults() {
	//
	if (map->getNrOfTreasuresLeft() == 0) {
		cout << "\nAll treasures have been found : \n";
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 3; j++)
				if (hunters[i].getPosY() == treasures[j].getPosY() && hunters[i].getPosX() == treasures[j].getPosX())
					cout << hunters[i].getName() << " found " << treasures[j].getName() << '\n';
	}
}


ostream& GameEngine::printHunters(ostream& out) {
	out << "\nThese are the hunters : \n";
	for (int i = 0; i < 4; i++)
		out << hunters[i] << '\n';
	return out;
}


ostream& GameEngine::printTreasures(ostream& out) {
	out << "\nThese are the treasures : \n";
	for (int i = 0; i < 3; i++)
		out << treasures[i] << '\n';
	return out;
}

GameEngine::~GameEngine()
{
}
