#include "Player.h"

Player::Player()
{
	moveType = 1;
	symbol = 'P';
	alive = true;
}

Player::Player(int X, int Y)
{
	moveType = 1;
	locationX = X;
	locationY = Y;
	alive = true;
}

Player::Player(int X, int Y, char C)
{
	moveType = 1;
	locationX = X;
	locationY = Y;
	symbol = C;
	alive = true;
}

void Player::death()
{
	exit(0);
}

bool Player::getAlive()
{
	return alive;
}

void Player::setAlive(bool B)
{
	alive = B;
}

