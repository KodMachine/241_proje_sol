#include "Trap.h"

Trap::Trap()
{
	symbol = '^';
	color = 14;
	bg_color = 12;
}

Trap::Trap(int X, int Y)
{
	locationX = X;
	locationY = Y;
	symbol = '^';
	color = 14;
	bg_color = 12;
}

Trap::Trap(int X, int Y, char C)
{
	locationX = X;
	locationY = Y;
	symbol = C;
	color = 14;
	bg_color = 12;
}

