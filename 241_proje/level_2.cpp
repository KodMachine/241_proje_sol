#include "level_2.h"
#include <time.h>

Level_2::Level_2()
{
	victory = false;
	objects[0] = &p;
	objects[1] = &t;
	objects[2] = &h;
	objects[3] = &v;
	objects[4] = &v2;
	map = new bool* [61];
	for (int i = 0; i < 61; ++i)
	{
		map[i] = new bool[16];
	}
}

Level_2::~Level_2()
{
	for (int i = 0; i < 61; ++i)
	{
		delete[] map[i];
	}
	delete[] map;
}

void Level_2::drawMap()
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
	compX = finishX - 1;
	rlutil::locate(compX, compY);
	std::cout << 'F';
	rlutil::resetColor();

	spawnPlayer(2 + startPointX, 9 + startPointY);
	spawnHorizontalEnemy(45 + startPointX, 9 + startPointY, &h);
	spawnVerticalEnemy(16 + startPointX, 9 + startPointY, &v);
	spawnVerticalEnemy(46 + startPointX, 1 + startPointY, &v2);
	placeTrap(25 + startPointX, 9 + startPointY, &t);
}

void Level_2::deleteMap()
{
}

void Level_2::getInfo()
{
	loading();
	rlutil::cls();
	rlutil::setColor(10);
	rlutil::locate(36, 10); std::cout << "LEVEL 2";
	rlutil::msleep(1300);
	rlutil::cls();
	rlutil::resetColor();
}

int Level_2::getCompX()
{
	return compX;
}

int Level_2::getCompY()
{
	return compY;
}

void Level_2::spawnPlayer(int x, int y)
{
	objects[0]->setLocationX(x);
	objects[0]->setLocationY(y);
	objects[0]->draw();
}

void Level_2::spawnHorizontalEnemy(int x, int y, Horizontal_Enemy* obj)
{
	obj->setLocationX(x);
	obj->setLocationY(y);
	obj->draw();
}

void Level_2::spawnVerticalEnemy(int x, int y, Vertical_Enemy* obj)
{
	obj->setLocationX(x);
	obj->setLocationY(y);
	obj->draw();
}

void Level_2::placeTrap(int x, int y, Trap* obj)
{
	obj->setLocationX(x);
	obj->setLocationY(y);
	obj->draw();
}

bool Level_2::isFinish(int a, int b)
{
	if (a == compX && b == compY)
	{
		p.victory();
		return true;
	}
	else
		return false;
}

void Level_2::playIntro()
{
	srand(time(NULL));

	bool flag = true;
	while (flag)
	{
		int randX = rand() % (finishX - startPointX - 1) + startPointX + 1;
		int randY = rand() % (finishY - startPointY - 1) + startPointY + 1;
		rlutil::cls();
		rlutil::setColor(10);
		rlutil::locate(randX, randY); std::cout << "PRESS \"ENTER\" TO PLAY  :')";
		rlutil::msleep(1000);
		if (kbhit())
		{
			int crs = rlutil::getkey();
			if (crs == rlutil::KEY_ENTER)
			{
				flag = false;
			}
		}
	}
}

void Level_2::loading()
{

	rlutil::saveDefaultColor();
	rlutil::cls();
	rlutil::setColor(10);
	rlutil::locate(32, 10); std::cout << "Loading...";
	for (int x = 20; x <= 52; x++)
	{
		for (int y = 11; y <= 13; y++)
		{
			rlutil::setBackgroundColor(8);
			rlutil::setColor(8);
			if (y == 11) { rlutil::locate(x, y); std::cout << "O"; }
			if (x == 20) { rlutil::locate(x, y); std::cout << "O"; }
			if (y == 13) { rlutil::locate(x, y); std::cout << "O"; }
			if (x == 52) { rlutil::locate(x, y); std::cout << "O"; }
		}
	}
	rlutil::msleep(2000);
	for (int x = 21; x <= 51; x++)
	{
		rlutil::msleep(300);
		rlutil::setBackgroundColor(10);
		rlutil::setColor(10);
		//:):):):):):):):):)
		if (x == 50)
		{
			rlutil::msleep(4000);
		}
		rlutil::locate(x, 12); std::cout << "O";

	}
	rlutil::cls();
	rlutil::resetColor();
}

