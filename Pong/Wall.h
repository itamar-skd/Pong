#pragma once
#include "defines.h"

class Wall
{
	protected:
		uint8_t _lowerIndex;
		uint8_t _height;

	public:
		Wall(uint8_t lowerIndex, uint8_t height);
		~Wall() = default;

	public:
		uint8_t lowerIndex();
		uint8_t height();

		void setLowerIndex(uint8_t lowerIndex);
		void setHeight(uint8_t height);
};

class EnemyWall final : public Wall
{
	private:
		DirectionVertical __dirVert;

	public:
		EnemyWall(uint8_t lowerIndex, uint8_t height, DirectionVertical dirVert);
		~EnemyWall() = default;

	public:
		DirectionVertical dirVert();
		void setDirVert(DirectionVertical dirVert);

		void move(uint8_t graphLength);
};

class PlayerWall final : public Wall
{
	public:
		PlayerWall(uint8_t lowerIndex, uint8_t height);
		~PlayerWall() = default;

	public:
		void move(DirectionVertical inputDirection, uint8_t graphLength);
};