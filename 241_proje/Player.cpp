#include "Player.h"

Player::Player()
{
	moveType = 3;
	symbol = 'P';
	alive = true;
}

Player::Player(int X, int Y)
{
	locationX = X;
	locationY = Y;
	alive = true;
}

Player::Player(int X, int Y, char C)
{
	locationX = X;
	locationY = Y;
	symbol = C;
	alive = true;
}

void Player::death()
{
}

bool Player::getAlive()
{
	return alive;
}

void Player::setAlive(bool B)
{
	alive = B;
}
