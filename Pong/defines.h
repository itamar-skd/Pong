#pragma once

#include <stdint.h>

typedef struct s_Pos_T
{
	uint8_t x;
	uint8_t y;

	s_Pos_T(uint8_t x, uint8_t y)
		: x(x)
		, y(y)
	{};

} screenPos;

enum DirectionVertical		: uint8_t { DIRECTION_UP = 1, DIRECTION_DOWN = 2 };
enum DirectionHorizontal	: uint8_t { DIRECTION_RIGHT = 1, DIRECTION_LEFT = 2 };

#define KEY_UP 72
#define KEY_DOWN 80