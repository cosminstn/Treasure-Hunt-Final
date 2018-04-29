#include "stdafx.h"
#include "Hunter.h"
#include "MapEntity.h"
#include <string>
Hunter::Hunter()
{
}

Hunter::Hunter(char* newName, unsigned int newPosX, unsigned int newPosY) : MapEntity(newPosX, newPosY) {

}

istream& operator>>(istream& in, Hunter& obj) {
	char *tName = new char[500];
	in.getline(tName, 499);
	obj.name = new char(sizeof(tName));
	strcpy_s(obj.name, sizeof(obj.name), tName);
	return in;
}

ostream& operator<<(ostream& out, Hunter &obj) {
	out << obj.name << '\n';
	out << "X : " << obj.getPosX() << " Y : " << obj.getPosY();
	return out;
}


void Hunter::moveTo(unsigned int newX, unsigned int newY, char **map) {
	map[this->getPosX()][this->getPosY()] = ' ';
	map[newX][newY] = 'H';
	this->setPosX(newX);
	this->setPosY(newY);
	
}

void Hunter::setName(char* newName) {
	this->name = new char(sizeof(newName));
	strcpy_s(this->name, sizeof(this->name), newName);
}

char* Hunter::getName() {
	return this->name;
}

Hunter::~Hunter()
{
}
