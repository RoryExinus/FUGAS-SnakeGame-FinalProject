#include "GameController.h"

void GameController::generateRandomFruitPos()
{
	fruitX = rand() % width;
	fruitY = rand() % height;
}



void GameController::setFlag(int c_flag)
{
	this->flag = c_flag;
}

void GameController::setSpeed(int speed)
{
	this->speed = speed;
}


void GameController::draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				std::cout << "#";
			}
			if (i == snake.getHead().getHeadY() && j == snake.getHead().getHeadX())
			{
				std::cout << "O";
			}
			else if (i == fruitY && j == fruitX)
			{
				std::cout << "@";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < snake.getTailLength(); k++)
				{
					if (snake.getTail(k).getTailY() == i && snake.getTail(k).getTailX() == j)
					{
						std::cout << "o";
						print = true;
					}
				}
				if (!print)
				{
					std::cout << " ";
				}
			}

			if (j == width - 1)
			{
				std::cout << "#";
			}
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < width + 2; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	std::cout << "Score" << score << std::endl;

}

void GameController::logic()	
{
	Tail prevTail = snake.getTail(0);
	snake.setSnakeTail(0, snake.getHead().getHeadX(), snake.getHead().getHeadY());
	Tail prevSecTail;
	for (int i = 1; i < snake.getTailLength(); i++)
	{
		prevSecTail.setTail(snake.getTail(i).getTailX(), snake.getTail(i).getTailY());
		snake.setSnakeTail(i, prevTail.getTailX(), prevTail.getTailY());
		prevTail.setTail(prevSecTail.getTailX(), prevSecTail.getTailY());
	}

	snake.moveMent();

	if (flag == 0)
	{
		if (snake.getHead().getHeadX() > width || snake.getHead().getHeadX() < 0
			|| snake.getHead().getHeadY() > height || snake.getHead().getHeadY() < 0)
		{
			this->gameOver = true;
		}
	}
	else if (flag == 1)
	{
		if (snake.getHead().getHeadX() >= width)
		{
			snake.setHeadX(0);
		}
		else if (snake.getHead().getHeadX() < 0)
		{
			snake.setHeadX(width - 1);
		}
		if (snake.getHead().getHeadY() >= height)
		{
			snake.setHeadY(0);
		}
		else if (snake.getHead().getHeadY() < 0)
		{
			snake.setHeadY(height - 1);
		}
	}
	else
	{
		this->gameOver = true;
		std::cout << "Wrong Flag\n";
	}

	for (int i = 0; i < snake.getTailLength(); i++)
	{
		if (snake.getTail(i).getTailX() == snake.getHead().getHeadX() && snake.getTail(i).getTailY() == snake.getHead().getHeadY())
		{
			this->gameOver = true;
		}
	}
	if (snake.getHead().getHeadX() == fruitX && snake.getHead().getHeadY() == fruitY)
	{
		score += 10;
		generateRandomFruitPos();
		snake.addTailLength();

	}
}

void GameController::play(Snake csnake)
{
	setup(csnake);
	while (!gameOver)
	{
		draw();
		snake.input();
		logic();
		Sleep(speed);
	}

}

void GameController::setup(Snake csnake)
{
	snake = csnake;
	snake.setStartState(width, height);
	this->gameOver = false;
	generateRandomFruitPos();
	this->score = 0;
}
