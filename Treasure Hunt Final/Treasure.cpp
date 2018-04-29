#include "stdafx.h"
#include "Treasure.h"


using namespace std;

Treasure::Treasure()
{
}

void Treasure::moveTo(unsigned int newY, unsigned int newX, Map& map) {
	if (newX >= 1 && newY >= 1 && newX <= map.getWidth() && newY <= map.getHeight())
	{
		map.clearLocation(this->getPosY(), this->getPosX());
		this->setPosY(newY);
		this->setPosX(newX);
		map.setItemAtLocation(newY, newX, 'T');
	}
}

void Treasure::setName(string newName) {
	this->name = newName;
}

string Treasure::getName() {
	return this->name;
}

istream &operator>>(istream &in, Treasure &obj) {
	in >> obj.name;
	return in;
}

ostream &operator<<(ostream &out, Treasure &obj) {
	out << obj.getName() << '\n';
	out << "X : " << obj.getPosX() << " Y : " << obj.getPosY();
	return out;
}

Treasure::~Treasure()
{
	
}
