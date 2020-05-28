#pragma once
#include "Object.h"
class Player:public Object
{
public:

	Player();
	Player(int, int);
	Player(int, int, char);
	void death();
	bool getAlive();
	void setAlive(bool);
	void victory();

private:

	bool alive;

};

