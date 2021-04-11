#pragma once
#include<iostream>
#include"SnakeController.h"
#include<windows.h>


class GameController
{
	bool gameOver;

	int fruitX, fruitY;
	int score;
	int flag;
	int speed;

	Snake snake;

	SnakeController snkCntrllr;

	const int width = 20;
	const int height = 20;

	void generateRandomFruitPos();

public:
	void setFlag(int c_flag);
	void setSpeed(int speed);
	void draw();
	void logic();
	void play(Snake csnake);
	void setup(Snake csnake);


};

