#pragma once
#include "Snake.h"
#include<conio.h>
class SnakeController
{
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	Snake snake;
	
public:

	eDirection drctn;

	void setSnake(Snake c_snake);
	Snake getSnake();
	bool checkTail(int x, int y);
	void input();
	void setStartState(int width, int height);

	void moveMent();



};

