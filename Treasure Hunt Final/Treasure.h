#pragma once
#include "MapEntity.h"
#include "Map.h"

class Treasure : public MapEntity
{
public:
	//Constructors and destructors
	Treasure();
	Treasure(char*, unsigned int, unsigned int);
	~Treasure();

	//Methods
	friend istream & operator>>(istream & , Treasure &);
	friend ostream & operator<<(ostream &, Treasure &);

	void moveTo(unsigned int, unsigned int, Map &map);
	void setName(string newName);
	string getName();
private:
	string name;
};

