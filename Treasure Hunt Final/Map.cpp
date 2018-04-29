#include "stdafx.h"
#include "Map.h"


Map::Map()
{
}

Map::Map(int height, int width, char initializer) {
	this->initializer = initializer;
	this->height = height;
	this->width = width;
	map = new char*[height + 1];
	for (int i = 0; i <= height; i++)
		map[i] = new char[width] + 1;
	for (int i = 0; i <= height; i++)
		for (int j = 0; j <= width; j++)
			map[i][j] = initializer;
	treasuresLeft = 3;
}

int Map::getHeight() {
	return this->height;
}

int Map::getWidth() {
	return this->width;
}

char Map::getItemAtLocation(int posY, int posX) {
	if(posY >= 1 && posY <= height && posX >= 1 && posX <= width)
		return map[posY][posX];
	return ' ';	//representation of a null characters
}

void Map::setItemAtLocation(int posY, int posX, char itemIdentifier) {
	if (itemIdentifier == 'H' || itemIdentifier == 'T') {
		//checks if it is a treasure on the specified location
		if (map[posY][posX] == 'T')
			treasuresLeft--;
		map[posY][posX] = itemIdentifier;
	}
}

void Map::clearLocation(int posY, int posX) {
	//we must know the the location has been previously visited, so we can't set it to be the same as the initializer
	map[posY][posX] = visitedPlace;
}

void Map::printMap() {
	cout << "\nMap width : " << width << " height : " << height << '\n';
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
			cout << map[i][j];
		cout << '\n';
	}
}

bool Map::isLocationVirgin(int posY, int posX) {
	//checks if a locations is virgin, i.e. it has not been visited yet
	if (posY >= 1 && posX >= 1 && posY <= height && posX <= width)
		return map[posY][posX] == initializer;
	return false;
}

int Map::getNrOfTreasuresLeft() {
	return treasuresLeft;

}

vector<pair<int, int>> Map::getSurroundingVirginBlocks(int posY, int posX) {
	//returns a vector of the blocks not visited yet that are near the given coordinates 
	
	vector<pair<int, int>> results;
	//up left
	results.push_back(make_pair(posY - 1, posX - 1));
	//up
	results.push_back(make_pair(posY - 1, posX));
	//up right
	results.push_back(make_pair(posY - 1, posX + 1));
	//right
	results.push_back(make_pair(posY, posX + 1));
	//right down
	results.push_back(make_pair(posY + 1, posX + 1));
	//down
	results.push_back(make_pair(posY + 1, posX));
	//down left
	results.push_back(make_pair(posY + 1, posX - 1));
	//left
	results.push_back(make_pair(posY, posX - 1));

	//filtered results
	//get final results by eliminating results that are not valid
	vector<pair<int, int>> finalResults;

	//check for treasures right near the current positions
	for (int i = 0; i < results.size(); i++)
		if (getItemAtLocation(results[i].first, results[i].second) == 'T')
		{
			//if we have found a treasure we can stop
			finalResults.push_back(make_pair(results[i].first, results[i].second));
			return finalResults;
			//that way if a hunter is standing right next to a treasure he will be able to go straight to it
		}

	//push a position only if it is virgin or it has a treasure on it
	for (int i = 0; i < results.size(); i++)
		if (results[i].first >= 1 && results[i].first <= height && results[i].second >= 1 && results[i].second < width)
			if (isLocationVirgin(results[i].first, results[i].second) || getItemAtLocation(results[i].first, results[i].second) == 'T')
				finalResults.push_back(results[i]);
	return finalResults;
}

Map::~Map()
{
}
