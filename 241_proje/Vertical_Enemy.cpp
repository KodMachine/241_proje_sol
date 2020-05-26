#include "Vertical_Enemy.h"

Vertical_Enemy::Vertical_Enemy()
{
	moveType = 2;
	symbol = 'V';
}

Vertical_Enemy::Vertical_Enemy(int X, int Y)
{
	moveType = 2;
	locationX = X;
	locationY = Y;
}

Vertical_Enemy::Vertical_Enemy(int X, int Y, char C)
{
	moveType = 3;
	locationX = X;
	locationY = Y;
	symbol = C;
}


