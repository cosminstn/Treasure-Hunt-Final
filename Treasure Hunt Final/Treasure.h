#pragma once
#include "MapEntity.h"
class Treasure : public MapEntity
{
public:
	//Constructors and destructors
	Treasure();
	Treasure(char*, unsigned int, unsigned int);
	~Treasure();

	//Methods
	friend istream& operator>>(istream& in, Treasure& obj);
	friend ostream& operator<<(ostream& out, Treasure& obj);
	void moveTo(unsigned int, unsigned int);
private:
	char *name;
};

