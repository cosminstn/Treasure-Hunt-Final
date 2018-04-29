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

}

int Map::getHeight() {
	return this->height;
}

int Map::getWidth() {
	return this->width;
}

char Map::getItemAtLocation(int posY, int posX) {
	return map[posY][posX];
}

void Map::setItemAtLocation(int posY, int posX, char itemIdentifier) {
	if (itemIdentifier == 'H' || itemIdentifier == 'T' || itemIdentifier == 'x')
		map[posY][posX] = itemIdentifier;
}

void Map::clearLocation(int posY, int posX) {
	map[posY][posX] = initializer;
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
	//push a position only if it is virgin or it has a treasure on it
	for (int i = 0; i < results.size(); i++)
		if (results[i].first >= 1 && results[i].first <= height && results[i].second >= 1 && results[i].second < width)
			if (isLocationVirgin(results[i].first, results[i].second) && getItemAtLocation(results[i].first, results[i].second) == 'T')
				finalResults.push_back(results[i]);
	return finalResults;
}

Map::~Map()
{
}
