#include "Ball.h"

Ball::Ball(uint8_t x, uint8_t y, DirectionVertical dirVert, DirectionHorizontal dirHrz)
	: __pos(x, y)
	, __dirVert(dirVert)
	, __dirHrz(dirHrz)
{}

screenPos& Ball::pos()
{
	return this->__pos;
}

DirectionVertical Ball::dirVert()
{
	return this->__dirVert;
}

DirectionHorizontal Ball::dirHrz()
{
	return this->__dirHrz;
}

void Ball::setDirHrz(DirectionHorizontal dirHrz)
{
	this->__dirHrz = dirHrz;
}

// This function does not determine whether the ball hit the wall. 
// It only determines if it's trying to go out of bounds, in which case would mean either player lost.
bool Ball::move(uint8_t graphLength)
{
	switch (this->__dirVert)
	{
		case DIRECTION_UP:
			this->__pos.y -= 1;
			if (this->__pos.y == 0)
				this->__dirVert = DIRECTION_DOWN;

			break;

		case DIRECTION_DOWN:
			this->__pos.y += 1;
			if (this->__pos.y == graphLength - 1)
				this->__dirVert = DIRECTION_UP;

			break;
	}

	switch (this->__dirHrz)
	{
		case DIRECTION_RIGHT:
			this->__pos.x += 1;
			if (this->__pos.x == graphLength - 1)
				return true;

			break;

		case DIRECTION_LEFT:
			this->__pos.x -= 1;
			if (this->__pos.x == 0)
				return true;

			break;
	}

	return false;
}