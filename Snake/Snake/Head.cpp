#include "Head.h"

Head::Head()
{
	this->headX = 0;
	this->headY = 0;
}

int Head::getHeadX()
{
	return headX;
}

int Head::getHeadY()
{
	return headY;
}

void Head::setHeadX(int x)
{
	this->headX = x;
}

void Head::setHeadY(int y)
{
	this->headY = y;
}

void Head::addHeadX(int x)
{
	this->headX += x;
}

void Head::addHeadY(int y)
{
	this->headY += y;
}




