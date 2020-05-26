#pragma once
#include "Map.h"
#include "Player.h"
#include "Trap.h"
#include "Vertical_Enemy.h"
#include "Horizontal_Enemy.h"

class Level_1:public Map
{
public:

	Level_1();
	~Level_1();
	void drawMap();
	void deleteMap();
	void getInfo();

	Object *objects[4];
	void spawnPlayer(int, int);
	void spawnHorizontalEnemy(int, int);
	void spawnVerticalEnemy(int, int);
	void placeTrap(int, int);
	bool*& operator[](const int &index)
	{
		return map[index];
	}

private:

	bool victory;

};

