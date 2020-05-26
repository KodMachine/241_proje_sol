#include "Object.h"

Object::Object()
{
	moveType = 0;
	locationX = 0;
	locationY = 0;
	symbol = '0';
	step = 1;
	
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

int Object::getMoveType()
{
	return moveType;
}

int Object::getStep()
{
	return step;
}

void Object::setStep(int a)
{
	step = a;
}

void Object::setSymbol(char c)
{
	symbol = c;
}


void Object::draw()
{
	rlutil::locate(locationX, locationY); std::cout << symbol;
}
