#pragma once
#include "Map.h"
#include "Player.h"
#include "Trap.h"
#include "Vertical_Enemy.h"
#include "Horizontal_Enemy.h"

//custom design level 2 
class Level_2 :public Map
{
public:
	Level_2();
	~Level_2();
	void drawMap();
	void deleteMap();
	void getInfo();
	int getCompX();
	int getCompY();
	Object* objects[10];
	void spawnPlayer(int, int);
	void spawnHorizontalEnemy(int, int, Horizontal_Enemy* obj);
	void spawnVerticalEnemy(int, int, Vertical_Enemy* obj);
	void placeTrap(int, int, Trap* obj);
	bool isFinish(int, int);
	void playIntro();
	Player p;
	Vertical_Enemy v;
	Vertical_Enemy v2;
	Vertical_Enemy v3;
	Vertical_Enemy v4;
	Horizontal_Enemy h;
	Horizontal_Enemy h2;
	Horizontal_Enemy h3;
	Trap t;
	Trap t2;

private:
	void loading();
	int compX;
	int compY;
	bool victory;

};

