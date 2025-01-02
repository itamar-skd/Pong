#pragma once
#include "defines.h"

class Ball
{
	private:
		screenPos __pos;
		DirectionVertical __dirVert;
		DirectionHorizontal __dirHrz;

	public:
		Ball(uint8_t x, uint8_t y, DirectionVertical dirVert, DirectionHorizontal dirHrz);
		~Ball() = default;

		screenPos& pos();
		DirectionVertical dirVert();
		DirectionHorizontal dirHrz();

		void setDirHrz(DirectionHorizontal dirHrz);

		bool move(uint8_t graphLength);
};

