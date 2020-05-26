#ifndef MAP_H
#define MAP_H

#include <iostream>
class Map
{
public:

	Map();
	virtual void drawMap() = 0;
	virtual void deleteMap() = 0;
	virtual void getInfo() = 0;
	void playIntro();
	bool** map;
	
protected:

	int startPointX;
	int startPointY;
	int finishX;
	int finishY;

};

#endif