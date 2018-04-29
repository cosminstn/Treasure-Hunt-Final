#pragma once
#include "MapEntity.h"
class Hunter : public MapEntity
{
public:
	//Constructors and destructors
	Hunter();
	Hunter(char*, unsigned int, unsigned int);
	~Hunter();

	//Methods
	friend istream& operator>>(istream& in, Hunter& obj);
	friend ostream& operator<<(ostream& out, Hunter& obj);
	void moveTo(unsigned int posX, unsigned int posY, char **map);
	void setName(char*);
	char* getName();

private:
	char *name;
};

