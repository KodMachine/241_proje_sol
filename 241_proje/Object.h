#pragma once
#include <iostream>
#include "rlutil.h"

class Object
{
protected:

	//instant coordinates
	int locationX;
	int locationY;

	//defines the move type of the object 0 -> non-movable 1 -> vertical 2 -> horizontal 3 -> input bound
	int moveType;

	//symbol of the object shown in console
	char symbol;

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



};






