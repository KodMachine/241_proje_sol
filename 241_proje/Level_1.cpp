#include "Level_1.h"

Level_1::Level_1()
{
	victory = false;
	objects[0] = new Player;
	objects[1] = new Trap;
	objects[2] = new Horizontal_Enemy;
	objects[3] = new Vertical_Enemy;
	map = new bool * [61];
	for (int i = 0; i < 61; ++i)
	{
		map[i] = new bool[16];
	}
}

Level_1::~Level_1()
{
	for (int i = 0; i < 61; ++i)
	{
		delete[] map[i];
	}
	delete[] map;
}

void Level_1::drawMap()
{
	for (int x = startPointX; x <= finishX; x++)
	{
		for (int y = startPointY; y <= finishY; y++)
		{
			if (y == startPointY) { rlutil::locate(x, y); std::cout << "O"; map[x - startPointX][y - startPointY] = false; }
			if (x == startPointX) { rlutil::locate(x, y); std::cout << "O"; map[x - startPointX][y - startPointY] = false; }
			if (y == finishY) { rlutil::locate(x, y); std::cout << "O"; map[x - startPointX][y - startPointY] = false; }
			if (x == finishX) { rlutil::locate(x, y); std::cout << "O"; map[x - startPointX][y - startPointY] = false; }
			if (y == 10 + startPointY) { rlutil::locate(x, y); std::cout << "O"; map[x - startPointX][y - startPointY] = false; }
		}
	}
	spawnPlayer(1 + startPointX, 9 + startPointY);
	spawnHorizontalEnemy(8, 7);
	spawnVerticalEnemy(9, 8);
	placeTrap(10, 10);
}

void Level_1::deleteMap()
{
}

void Level_1::getInfo()
{
}

void Level_1::spawnPlayer(int x, int y)
{
	objects[0]->setLocationX(x);
	objects[0]->setLocationY(y);
	objects[0]->draw();
}

void Level_1::spawnHorizontalEnemy(int x, int y)	
{
	objects[2]->setLocationX(x);
	objects[2]->setLocationY(y);
	objects[2]->draw();
}

void Level_1::spawnVerticalEnemy(int x, int y)
{
	objects[3]->setLocationX(x);
	objects[3]->setLocationY(y);
	objects[3]->draw();
}

void Level_1::placeTrap(int x, int y)
{
	objects[1]->setLocationX(x);
	objects[1]->setLocationY(y);
	objects[1]->draw();
}

