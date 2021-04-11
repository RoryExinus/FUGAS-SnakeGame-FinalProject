#include "SnakeController.h"


void SnakeController::setSnake(Snake c_snake)
{ 
	this->snake = c_snake;
}
Snake SnakeController::getSnake()
{
	return snake;
}
bool SnakeController::checkTail(int x, int y)
{
	if (snake.getHead().getHeadX() + x == snake.getTail(1).getTailX() && snake.getHead().getHeadY() + y == snake.getTail(1).getTailY())
	{
		return true;
	}
	return false;
}

void SnakeController::input()
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

void SnakeController::setStartState(int width, int height)
{
	drctn = STOP;
	snake.getHead().setHeadX(width / 2);
	snake.getHead().setHeadY(height / 2);
}

void SnakeController::moveMent()
{
	switch (drctn)
	{
	case LEFT:
		if (checkTail(-1, 0))
		{
			snake.getHead().addHeadX(1);
		}
		else
		{
			snake.getHead().addHeadX(-1);

		}
		break;

	case RIGHT:
		if (checkTail(1, 0))
		{
			snake.getHead().addHeadX(-1);
		}
		else
		{
			snake.getHead().addHeadX(1);

		}
		break;

	case UP:
		if (checkTail(0, -1))
		{
			snake.getHead().addHeadY(1);
		}
		else
		{
			snake.getHead().addHeadY(-1);

		}
		break;

	case DOWN:
		if (checkTail(0, 1))
		{
			snake.getHead().addHeadY(-1);
		}
		else
		{
			snake.getHead().addHeadY(1);

		}
		break;

	default:
		break;
	}
}
