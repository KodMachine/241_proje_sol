#pragma once 
#include "Level_1.h"
#include "level_2.h"
class Run
{
	public:
		
		Run();

		void moveEnemy(Object* &v,bool** map);
		void movePlayer(Object*& v, bool** map, int i);
		void play();
		void runLevel_1(Level_1 level);
		void finish();
	private:
		Level_1 level;
		Level_2 level2;
		int deathCount;
		void showDeathCount();
};

