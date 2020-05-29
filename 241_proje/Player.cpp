#include "Player.h"

Player::Player()
{
	moveType = 1;
	symbol = 'O';
	alive = true;
	color = 13;
	bg_color = 0;
}

Player::Player(int X, int Y)
{
	moveType = 1;
	locationX = X;
	locationY = Y;
	symbol = 'O';
	alive = true;
	color = 13;
	bg_color = 0;
}

Player::Player(int X, int Y, char C)
{
	moveType = 1;
	locationX = X;
	locationY = Y;
	symbol = C;
	alive = true;
	color = 13;
	bg_color = 0;
}

void Player::death()
{
	char isDone;
	rlutil::cls();
	rlutil::setColor(12);
	rlutil::locate(36,10); std::cout << "YOU ARE DEAD :')";
	rlutil::msleep(1300);
	rlutil::resetColor();
	rlutil::cls();
	rlutil::msleep(150);
	rlutil::locate(20, 10); std::cout << "PLAY any key     " << "     EXIT E";
	rlutil::locate(36, 12); std::cout << "SO : ";
	std::cin >> isDone;
	if(isDone == 'e' || isDone == 'E')
	{
		exit(0);
	}
	rlutil::cls();
}

bool Player::getAlive()
{
	return alive;
}

void Player::setAlive(bool B)
{
	alive = B;
}

void Player::victory()
{
	char isDone;

	rlutil::cls();
	rlutil::setColor(10);
	rlutil::locate(36, 10); std::cout << "WOW YOU WON !  :')";
	rlutil::msleep(1300);
	rlutil::locate(20, 10); std::cout << "PLAY anykey   " << "     EXIT ESC";
	rlutil::locate(36, 12); std::cout << "SO : ";
	std::cin >> isDone;
	if (isDone == 'e' || isDone == 'E')
	{
		exit(0);
	}
	rlutil::cls();
	rlutil::resetColor();

}

