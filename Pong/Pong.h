#pragma once
#include "Graph.h"
#include <thread>

class Pong
{
	private:
		Graph* __graph;
		bool __keepAlive;

		std::thread __inputThrd;
		std::thread __advanceThrd;

	public:
		Pong(uint8_t graphLength);
		~Pong();

	private:
		void input();
		void advance();
};

