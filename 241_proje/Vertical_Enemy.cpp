#include "Vertical_Enemy.h"

Vertical_Enemy::Vertical_Enemy()
{
	moveType = 2;
	symbol = 'V';
	color = 12;
	bg_color = 12;
}

Vertical_Enemy::Vertical_Enemy(int X, int Y)
{
	moveType = 2;
	locationX = X;
	locationY = Y;
	symbol = 'V';
	color = 12;
	bg_color = 12;
}

Vertical_Enemy::Vertical_Enemy(int X, int Y, char C)
{
	moveType = 3;
	locationX = X;
	locationY = Y;
	symbol = C;
	color = 12;
	bg_color = 12;
}


