#pragma once
#include "common.h"

class Box
{
public:
	Box();
	~Box();



private:
	// ‹éŒ`‚Ì’†‰›‚ÌÀ•W
	struct Vector2
	{
		int x = 0;
		int y = RATIO_Y * 60;
	};
};