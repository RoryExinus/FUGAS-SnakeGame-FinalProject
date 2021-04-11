#include "Tail.h"


Tail::Tail()
{
	this->tailX = 0;
	this->tailY = 0;
}


int Tail::getTailX()
{
	return tailX;
}

int Tail::getTailY()
{
	return tailY;
}

void Tail::setTail(int x, int y)
{
	this->tailX = x;
	this->tailY = y;
}


