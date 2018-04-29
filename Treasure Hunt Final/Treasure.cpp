#include "stdafx.h"
#include "Treasure.h"
#include <iostream>
using namespace std;

Treasure::Treasure()
{
}

void Treasure::moveTo(unsigned int newY, unsigned int newX, Map& map) {
	if (newX >= 1 && newY >= 1 && newX <= map.getWidth() && newY <= map.getHeight())
	{
		map.clearLocation(this->getPosY(), this->getPosX());
		this->setPosX(newX);
		this->setPosY(newY);
		map.setItemAtLocation(newY, newX, 'T');
	}
}

void Treasure::setName(string newName) {
	this->name = newName;
}

string Treasure::getName() {
	return this->name;
}

istream & operator>>(istream &in, Treasure &obj) {
	return in;
}

ostream & operator<<(ostream &out, Treasure& obj) {
	//out << obj.name;
	//not working for some strange reason
	return out;
}

Treasure::~Treasure()
{
	
}
