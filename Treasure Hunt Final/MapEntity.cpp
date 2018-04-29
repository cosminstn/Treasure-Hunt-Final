#include "stdafx.h"
#include "MapEntity.h"


MapEntity::MapEntity()
{
	
	this->posX = 0;
	this->posY = 0;
}

MapEntity::MapEntity(unsigned int posX, unsigned int posY) {
	this->posX = posX;
	this->posY = posY;
}

void MapEntity::setPosX(unsigned int newX) {
	this->posX = newX;
}

unsigned int MapEntity::getPosX() {
	return this->posX;
}

void MapEntity::setPosY(unsigned int newY) {
	this->posY = newY;
}

unsigned int MapEntity::getPosY() {
	return this->posY;
}

MapEntity::~MapEntity()
{
	//nothing to delete really
	this->posX = 0;
	this->posY = 0;
}
