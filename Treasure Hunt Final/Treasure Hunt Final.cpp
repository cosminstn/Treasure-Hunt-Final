// Treasure Hunt Final.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameEngine.h"
#include <iostream>
using namespace std;
int main()
{

	GameEngine game((char*)"GameConfig.init");
	game.printMap(cout);
	getchar();
    return 0;
}

