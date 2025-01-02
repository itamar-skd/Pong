#pragma once
#include "Ball.h"
#include "Wall.h"

class Graph
{
	private:
		uint8_t __graphLength;

		Ball* __ball;
		PlayerWall* __playerWall;
		EnemyWall* __enemyWall;

	public:
		Graph(uint8_t graphLength);
		~Graph();

	public:
		uint8_t graphLength();

		void print();

		bool moveBall();
		void movePlayerWall(DirectionVertical inputDirection);
		void moveEnemyWall();
};

