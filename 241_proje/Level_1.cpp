#include "Level_1.h"

Level_1::Level_1()
{
	victory = false;
	objects[0] = &p;
	objects[1] = &t;
	objects[2] = &h;
	objects[3] = &v;
	objects[4] = &v2;
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
	rlutil::cls();
	rlutil::saveDefaultColor();
	for (int x = startPointX; x <= finishX; x++)
	{
		for (int y = startPointY; y <= finishY; y++)
		{
			rlutil::resetColor();
			//draw path
			rlutil::setColor(10);
			if (y == 10 + startPointY) { rlutil::locate(x, y); std::cout << "^"; map[x - startPointX][y - startPointY] = false; }
			//draw frame
			rlutil::setBackgroundColor(8);
			rlutil::setColor(8);
			if (y == startPointY) { rlutil::locate(x, y); std::cout << "O"; map[x - startPointX][y - startPointY] = false; }
			if (x == startPointX) { rlutil::locate(x, y); std::cout << "O"; map[x - startPointX][y - startPointY] = false; }
			if (y == finishY) { rlutil::locate(x, y); std::cout << "O"; map[x - startPointX][y - startPointY] = false; }
			if (x == finishX) { rlutil::locate(x, y); std::cout << "O"; map[x - startPointX][y - startPointY] = false; }
		}
	}

	rlutil::resetColor();

	rlutil::setBackgroundColor(11);
	rlutil::setColor(0);
	compY = 9 + startPointY;
	compX = finishX - 1 ;
	rlutil::locate(compX, compY);
	std::cout << 'F' ;
	rlutil::resetColor();
	
	spawnPlayer(2 + startPointX, 9 + startPointY);
	spawnHorizontalEnemy(45+ startPointX, 9+startPointY, &h);
	spawnVerticalEnemy(16 + startPointX, 9 + startPointY, &v);
	spawnVerticalEnemy(46 + startPointX, 1 + startPointY, &v2);
	placeTrap(25 + startPointX, 9 + startPointY, &t);
}

void Level_1::deleteMap()
{
}

void Level_1::getInfo()
{
}

int Level_1::getCompX()
{
	return compX;
}

int Level_1::getCompY()
{
	return compY;
}

void Level_1::spawnPlayer(int x, int y)
{
	objects[0]->setLocationX(x);
	objects[0]->setLocationY(y);
	objects[0]->draw();
}

void Level_1::spawnHorizontalEnemy(int x, int y, Horizontal_Enemy* obj)	
{
	obj->setLocationX(x);
	obj->setLocationY(y);
	obj->draw();
}

void Level_1::spawnVerticalEnemy(int x, int y, Vertical_Enemy* obj)
{
	obj->setLocationX(x);
	obj->setLocationY(y);
	obj->draw();
}

void Level_1::placeTrap(int x, int y, Trap* obj)
{
	obj->setLocationX(x);
	obj->setLocationY(y);
	obj->draw();
}

bool Level_1::isFinish(int a , int b)
{
	if (a == compX && b == compY)
		return true;
	else
		return false;
}

void Level_1::playIntro()
{
}

