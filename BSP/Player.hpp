#pragma once
#include <iostream>
#include "Geometry.hpp"


class Player {
private:
	struct Moving {
		bool left, right, front, back;
	};

public:
	static const int FOV = 60;
	static const int FOG = 30;

	Moving moving;
	vec2f position = {1.0f, 1.0f};
	float angle = 0.f;

	void movement()
	{
		if (moving.left)
		{
			angle -= 0.055f;
		}
		else if (moving.right)
		{
			angle += 0.055f;
		}

		if (moving.front)
		{
			position.x += cos(angle) / 4; position.y += sin(angle) / 4;
		}
		else if (moving.back)
		{
			position.x -= cos(angle) / 4; position.y -= sin(angle) / 4;
		}
	}
};