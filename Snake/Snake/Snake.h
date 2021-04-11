#pragma once
#include "Head.h"
#include "Tail.h"
#include<conio.h>



class Snake
{


	Head head;
	Tail tail[100];
	int lengthTail;

	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirection drctn;

public:
	Snake();


	int getTailLength();
	Head getHead();
	Tail getTail(int itr);
	
	void addTailLength();
	void setSnakeTail(int iter, int x, int y);
	void setHeadX(int x);
	void setHeadY(int y);


	bool checkTail(int x, int y);
	void input();
	void setStartState(int width, int height);
	void moveMent();
	
};

