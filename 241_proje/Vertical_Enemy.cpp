#include "Vertical_Enemy.h"

Vertical_Enemy::Vertical_Enemy()
{
	moveType = 1;
	symbol = 'V';
}

Vertical_Enemy::Vertical_Enemy(int X, int Y)
{
	locationX = X;
	locationY = Y;
}

Vertical_Enemy::Vertical_Enemy(int X, int Y, char C)
{
	locationX = X;
	locationY = Y;
	symbol = C;
}