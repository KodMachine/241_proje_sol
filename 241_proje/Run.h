#pragma once 
#include "Level_1.h"

class Run
{
	public:
		Level_1 level;
		Run();

		void moveEnemy(Object* &v,bool** map);
		void movePlayer(Object*& v, bool** map, int i);
		void play();
		void runLevel_1(Level_1 level);
};

