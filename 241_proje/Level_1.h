#pragma once
#include "Map.h"
#include "Player.h"
#include "Trap.h"
#include "Vertical_Enemy.h"
#include "Horizontal_Enemy.h"

//custom design level 1 
class Level_1:public Map
{
public:
	Level_1();
	~Level_1();
	//draws map
	void drawMap();
	//deletes map
	void deleteMap();
	//info about map
	void getInfo();
	//finish locationX
	int getCompX();
	//finish locationY
	int getCompY();
	//players,enemies,traps etc 
	Object* objects[5];
	//spawns player given location
	void spawnPlayer(int, int);
	//spawns horizontal enemy to given locations
	void spawnHorizontalEnemy(int, int, Horizontal_Enemy* obj);
	//spawns vertical enemy to given locations
	void spawnVerticalEnemy(int, int, Vertical_Enemy* obj);
	//place traps to given locations
	void placeTrap(int, int, Trap* obj);
	//checks if level finished or not 
	bool isFinish(int, int);
	//displays intro messeges
	void playIntro();
	Player p;
	Vertical_Enemy v;
	Vertical_Enemy v2;
	Horizontal_Enemy h;
	Trap t;
	
private:
	void loading();
	int compX;
	int compY;
	bool victory;

};

