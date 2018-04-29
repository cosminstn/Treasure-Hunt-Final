#pragma once
#include <vector>
#include "Map.h"
using namespace std;
class MapEntity
{
public:
	MapEntity();
	MapEntity(unsigned int, unsigned int);
	~MapEntity();
	virtual void moveTo(unsigned int, unsigned int, Map &) = 0;
	void setPosX(unsigned int);
	unsigned int getPosX();
	void setPosY(unsigned int);
	unsigned int getPosY();
private:
	unsigned int posX, posY;
};

