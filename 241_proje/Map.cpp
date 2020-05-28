#include "Map.h"

Map::Map()
{
	startPointX = 5;
	startPointY = 5;
	finishX = 65;
	finishY = 20;
}

int Map::getstartPointX()
{
	return startPointX;
}

int Map::getStartPointY()
{
	return startPointY;
}

int Map::getFinishX()
{
	return finishX;
}

int Map::getFinishY()
{
	return finishY;
}
