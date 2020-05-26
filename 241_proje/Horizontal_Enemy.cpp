#include "Horizontal_Enemy.h"

Horizontal_Enemy::Horizontal_Enemy()
{
	moveType = 2;
	symbol = 'H';
}

Horizontal_Enemy::Horizontal_Enemy(int X, int Y)
{
	locationX = X;
	locationY = Y;
}

Horizontal_Enemy::Horizontal_Enemy(int X, int Y, char C)
{
	locationX = X;
	locationY = Y;
	symbol = C;
}