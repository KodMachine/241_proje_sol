#pragma once
#include <iostream>
#include "rlutil.h"

class Object
{
protected:

	//instant coordinates
	int locationX;
	int locationY;

	//symbol of the object shown in console
	char symbol;
	int color;
	int bg_color;

	//defines movetype of the object 1P 2V 3H 0T
	int moveType;
public:

	//default constructor
	Object();

	//prints the symbol of the object to given coordinates in console 
	void draw();

	//sets and gets
	int getLocationX();
	int getLocationY();
	void setLocationX(int);
	void setLocationY(int);
	int getMoveType();
	int step;
	int getStep();
	void setStep(int);
	void setSymbol(char);



};






