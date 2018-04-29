#pragma once
#include "MapEntity.h"
#include "Map.h"

class Hunter : public MapEntity
{
public:
	//Constructors and destructors
	Hunter();
	Hunter(string, unsigned int, unsigned int);
	~Hunter();

	//Methods
	friend istream& operator>>(istream& in, Hunter& obj);
	friend ostream& operator<<(ostream& out, Hunter& obj);
	void moveTo(unsigned int posX, unsigned int posY, Map &map);
	void setName(string);
	void setStatus(bool status);
	bool getStatus();
	string getName();

private:
	string name;
	bool isSearching;
};

