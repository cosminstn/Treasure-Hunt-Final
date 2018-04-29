#include "stdafx.h"
#include "Treasure.h"


Treasure::Treasure()
{
}

Treasure::Treasure(char* name, unsigned int newX, unsigned int newY) : MapEntity(newX, newY) {
	
}

istream& operator>>(istream &in, Treasure &obj) {
	return in;
}

ostream& operator<<(ostream &out, Treasure &obj) {
	return out;
}

void Treasure::moveTo(unsigned int newX, unsigned int newY) {
	this->setPosX(newX);
	this->setPosY(newY);
}

Treasure::~Treasure()
{
	delete name;
}
