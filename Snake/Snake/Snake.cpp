#include "Snake.h"

Snake::Snake()
{
	this->lengthTail = 0;
}



int Snake::getTailLength()
{
	return lengthTail;
}

Head Snake::getHead()
{
	return head;
}

Tail Snake::getTail(int itr)
{
	return tail[itr];
}

void Snake::addTailLength()
{
	this->lengthTail++;
}

void Snake::setSnakeTail(int iter, int x, int y)
{
	tail[iter].setTail(x, y);
}

void Snake::setHeadX(int x)
{
	head.setHeadX(x);
}

void Snake::setHeadY(int y)
{
	head.setHeadY(y);
}


bool Snake::checkTail(int x, int y)
{
	if (head.getHeadX() + x == tail[1].getTailX() && head.getHeadY() + y == tail[1].getTailY())
	{
		return true;
	}
	return false;
}

void Snake::input()
{
	if (_kbhit())
	{
		switch (_getch()) {
		case 'a':
			drctn = LEFT;
			break;
		case 'd':
			drctn = RIGHT;
			break;
		case 'w':
			drctn = UP;
			break;
		case 's':
			drctn = DOWN;
			break;
		}
	}
}

void Snake::setStartState(int width, int height)
{
	drctn = STOP;
	head.setHeadX (width / 2);
	head.setHeadY(height / 2);
}

void Snake::moveMent()
{
	switch (drctn)
	{
	case LEFT:
		if (checkTail(-1, 0))
		{
			head.addHeadX(1);
		}
		else
		{
			head.addHeadX(-1);

		}
		break;

	case RIGHT:
		if (checkTail(1, 0))
		{
			head.addHeadX(-1);
		}
		else
		{
			head.addHeadX(1);

		}
		break;

	case UP:
		if (checkTail(0, -1))
		{
			head.addHeadY(1);
		}
		else
		{
			head.addHeadY(-1);

		}
		break;

	case DOWN:
		if (checkTail(0, 1))
		{
			head.addHeadY(-1);
		}
		else
		{
			head.addHeadY(1);

		}
		break;

	default:
		break;
	}
}






