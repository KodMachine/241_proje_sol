#ifndef MAP_H
#define MAP_H
#include "Object.h"
#include <iostream>
class Map
{
public:

	Map();
	virtual void drawMap() = 0;
	virtual void deleteMap() = 0;
	virtual void getInfo() = 0;
	virtual void playIntro() = 0;
	bool** map;
	int getstartPointX();
	int getStartPointY();
	int getFinishX();
	int getFinishY();
	bool*& operator[](const int& index)
	{
		return map[index];
	}

protected:

	int startPointX;
	int startPointY;
	int finishX;
	int finishY;

};

#endif