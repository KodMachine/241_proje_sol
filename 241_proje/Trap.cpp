#include "Trap.h"

Trap::Trap()
{
	symbol = 'T';
}

Trap::Trap(int X, int Y)
{
	locationX = X;
	locationY = Y;
}

Trap::Trap(int X, int Y, char C)
{
	locationX = X;
	locationY = Y;
	symbol = C;
}

