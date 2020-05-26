#include "Object.h"

Object::Object()
{
	locationX = 0;
	locationY = 0;
	moveType = 0;
	symbol = '0';
}

int Object::getLocationX()
{
	return locationX;
}

int Object::getLocationY()
{
	return locationY;
}

void Object::setLocationX(int X)
{
	locationX = X;
}

void Object::setLocationY(int Y)
{
	locationY = Y;
}

void Object::draw()
{
	rlutil::locate(locationX, locationY); std::cout << symbol;
}
