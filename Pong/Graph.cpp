#include "Graph.h"
#include <string>
#include <iostream>
#include <cstdlib>

Graph::Graph(uint8_t graphLength)
	: __graphLength(graphLength)
	, __playerWall(new PlayerWall(graphLength / 2 + 1, 3))
{
	srand(time(0));

	DirectionVertical ballDirVert = (rand() % 2) == 0 ? DIRECTION_UP : DIRECTION_DOWN;
	DirectionHorizontal ballDirHrz = (rand() % 2) == 0 ? DIRECTION_RIGHT : DIRECTION_LEFT;

	this->__ball = new Ball(graphLength / 2, graphLength / 2, ballDirVert, ballDirHrz);

	DirectionVertical enemyWallDirVert = (rand() % 2) == 0 ? DIRECTION_UP : DIRECTION_DOWN;
	this->__enemyWall = new EnemyWall(graphLength / 2 + 1, 3, enemyWallDirVert);
}

Graph::~Graph()
{
	if (this->__ball != nullptr)
	{
		delete __ball;
		this->__ball = nullptr;
	}
	
	if (this->__playerWall != nullptr)
	{
		delete __playerWall;
		this->__playerWall = nullptr;
	}
	
	if (this->__enemyWall != nullptr)
	{
		delete __enemyWall;
		this->__enemyWall = nullptr;
	}
}

uint8_t Graph::graphLength()
{
	return this->__graphLength;
}

void Graph::print()
{
	system("cls");
	std::string res;
	
	for (size_t row{ 0 }; row < this->__graphLength; row++)
	{
		for (size_t col{ 0 }; col < this->__graphLength; col++)
		{
			screenPos& ballPos = this->__ball->pos();

			if (ballPos.x == col && ballPos.y == row)
			{
				res += '*';
				continue;
			}

			if (col == 0)
			{
				if ((this->__playerWall->lowerIndex() >= row) && ((this->__playerWall->lowerIndex() - (this->__playerWall->height() - 1)) <= row))
				{
					res += (char)254u;
					continue;
				}
			} 
			else if (col == this->__graphLength - 1)
			{
				if ((this->__enemyWall->lowerIndex() >= row) && ((this->__enemyWall->lowerIndex() - (this->__enemyWall->height() - 1)) <= row))
				{
					res += (char)254u;
					continue;
				}
			}

			res += ' ';
		}

		res += '\n';
	}

	std::cout << res;
}

bool Graph::moveBall()
{
	screenPos& ballPos = this->__ball->pos();
	if (ballPos.x == 1)
	{
		// If ball is next to player wall, turn right
		if ((this->__playerWall->lowerIndex() >= ballPos.y) && ((this->__playerWall->lowerIndex() - (this->__playerWall->height() - 1)) <= ballPos.y))
			this->__ball->setDirHrz(DIRECTION_RIGHT);
	}
	else if (ballPos.x == this->__graphLength - 2)
	{
		// If ball is next to enemy wall, turn left
		if ((this->__enemyWall->lowerIndex() >= ballPos.y) && ((this->__enemyWall->lowerIndex() - (this->__enemyWall->height() - 1)) <= ballPos.y))
			this->__ball->setDirHrz(DIRECTION_LEFT);

		// If ball is going down, enemy wall up, and the ball is one block higher than the wall, the ball would bounce from the wall at the moment they both move.
		if (this->__ball->dirVert() == DIRECTION_DOWN && this->__enemyWall->dirVert() == DIRECTION_UP
			&& this->__ball->pos().y == (this->__enemyWall->lowerIndex() - this->__enemyWall->height()))
			this->__ball->setDirHrz(DIRECTION_LEFT);
		
		// If ball is going up, enemy wall down, and the ball is one block lower than the wall, the ball would bounce from the wall at the moment they both move.
		if (this->__ball->dirVert() == DIRECTION_UP && this->__enemyWall->dirVert() == DIRECTION_DOWN
			&& this->__ball->pos().y == (this->__enemyWall->lowerIndex() + 1))
			this->__ball->setDirHrz(DIRECTION_LEFT);
	}

	bool gameOver = this->__ball->move(this->__graphLength);

	return gameOver;
}

void Graph::movePlayerWall(DirectionVertical inputDirection)
{
	this->__playerWall->move(inputDirection, this->__graphLength);
}

void Graph::moveEnemyWall()
{
	this->__enemyWall->move(this->__graphLength);
}