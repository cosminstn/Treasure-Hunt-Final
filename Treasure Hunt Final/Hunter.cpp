#include "stdafx.h"
#include "Hunter.h"
Hunter::Hunter()
{
}

Hunter::Hunter(string newName, unsigned int newPosX, unsigned int newPosY) : MapEntity(newPosX, newPosY) {
	this->name = newName;
	this->isSearching = true;
}

istream& operator>>(istream& in, Hunter& obj) {
	in >> obj.name;
	return in;
}

ostream& operator<<(ostream& out, Hunter &obj) {
	out << obj.name << '\n';
	out << "X : " << obj.getPosX() << " Y : " << obj.getPosY();
	return out;
}


void Hunter::moveTo(unsigned int newY, unsigned int newX, Map &map) {
	if(newX >= 1 && newY >= 1 && newX <= map.getWidth() && newY <= map.getHeight())
	{
		if (map.getItemAtLocation(newY, newX) == 'T') {
			//the hunter has found a treasure so it should no longer look
			this->setStatus(false);
		}
		map.clearLocation(this->getPosY(), this->getPosX());
		this->setPosX(newX);
		this->setPosY(newY);
		map.setItemAtLocation(newY, newX, 'H');
	}
}

void Hunter::setName(string newName) {
	this->name = newName;
}

void Hunter::setStatus(bool status) {
	this->isSearching = status;
}

bool Hunter::getStatus() {
	return this->isSearching;
}

string Hunter::getName() {
	return this->name;
}

Hunter::~Hunter()
{
}
