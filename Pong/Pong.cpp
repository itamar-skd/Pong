#include "Pong.h"
#include <conio.h>
#include <chrono>

using namespace std::chrono_literals;

Pong::Pong(uint8_t graphLength)
	: __graph(new Graph(graphLength))
	, __keepAlive(true)
	, __inputThrd(&Pong::input, this)
	, __advanceThrd(&Pong::advance, this)
{}

Pong::~Pong()
{
	this->__keepAlive = false;

	if (this->__graph != nullptr)
	{
		delete this->__graph;
		this->__graph = nullptr;
	}

	this->__inputThrd.join();
	this->__advanceThrd.join();
}

void Pong::input()
{
	int input;

	while (this->__keepAlive)
	{
		input = _getch();

		switch (input)
		{
			case KEY_UP:
				this->__graph->movePlayerWall(DIRECTION_UP);
				break;
			case KEY_DOWN:
				this->__graph->movePlayerWall(DIRECTION_DOWN);
				break;
			default:
				continue;
		}
	}
}

void Pong::advance()
{
	bool gameOver;
	
	while (this->__keepAlive)
	{
		gameOver = this->__graph->moveBall();
		this->__graph->moveEnemyWall();

		this->__graph->print();

		if (gameOver)
			this->~Pong();

		std::this_thread::sleep_for(500ms);
	}
}