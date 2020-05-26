#include "Horizontal_Enemy.h"

Horizontal_Enemy::Horizontal_Enemy()
{
	moveType = 3;
	symbol = 'H';
}

Horizontal_Enemy::Horizontal_Enemy(int X, int Y)
{
	moveType = 3;
	locationX = X;
	locationY = Y;
}

Horizontal_Enemy::Horizontal_Enemy(int X, int Y, char C)
{
	moveType = 3;
	locationX = X;
	locationY = Y;
	symbol = C;
}