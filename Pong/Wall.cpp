#include "Wall.h"

Wall::Wall(uint8_t lowerIndex, uint8_t height)
	: _lowerIndex(lowerIndex)
	, _height(height)
{}

uint8_t Wall::lowerIndex()
{
	return this->_lowerIndex;
}

uint8_t Wall::height()
{
	return this->_height;
}

void Wall::setLowerIndex(uint8_t lowerIndex)
{
	this->_lowerIndex = lowerIndex;
}

void Wall::setHeight(uint8_t height)
{
	this->_height = height;
}

EnemyWall::EnemyWall(uint8_t lowerIndex, uint8_t height, DirectionVertical dirVert)
	: Wall(lowerIndex, height)
	, __dirVert(dirVert)
{}

DirectionVertical EnemyWall::dirVert()
{
	return this->__dirVert;
}

void EnemyWall::setDirVert(DirectionVertical dirVert)
{
	this->__dirVert = dirVert;
}

void EnemyWall::move(uint8_t graphLength)
{
	switch (this->__dirVert)
	{
		case DIRECTION_UP:
			this->_lowerIndex = this->_lowerIndex - 1;
			if (this->_lowerIndex - (this->_height - 1) == 0)
			{
				this->__dirVert = DIRECTION_DOWN;
			}

			break;

		case DIRECTION_DOWN:
			this->_lowerIndex = this->_lowerIndex + 1;
			if (this->_lowerIndex == graphLength - 1)
			{
				this->__dirVert = DIRECTION_UP;
			}

			break;
	}
}

PlayerWall::PlayerWall(uint8_t lowerIndex, uint8_t height)
	: Wall(lowerIndex, height)
{};

void PlayerWall::move(DirectionVertical inputDirection, uint8_t graphLength)
{
	switch (inputDirection)
	{
		case DIRECTION_UP:
			if (this->_lowerIndex - (this->_height - 1) == 0)
				return;

			this->_lowerIndex--;
			break;

		case DIRECTION_DOWN:
			if (this->_lowerIndex == graphLength - 1)
				return;

			this->_lowerIndex++;
			break;
	}
}