#pragma once
#include "Map.h"
#include "Player.h"
#include "Trap.h"
#include "Vertical_Enemy.h"
#include "Horizontal_Enemy.h"

//custom design level 1 aaahah
class Level_1:public Map
{
public:
	Level_1();
	~Level_1();
	void drawMap();
	void deleteMap();
	void getInfo();
	int getCompX();
	int getCompY();
	Object* objects[4];
	void spawnPlayer(int, int);
	void spawnHorizontalEnemy(int, int);
	void spawnVerticalEnemy(int, int);
	void placeTrap(int, int);
	bool isFinish(int, int);
	Player p;
	Vertical_Enemy v;
	Horizontal_Enemy h;
	Trap t;
	
private:
	int compX;
	int compY;
	bool victory;

};

