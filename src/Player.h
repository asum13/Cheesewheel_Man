#pragma once
#include "Vector2d.h"
class Player
{
public:
	Vector2d position;
	float playerSpeed = 200.f;
	float size = 30.f;
	int currentDirection = 0;

	void Move();

	void Draw(Vector2d aimDirection);

	Vector2d PlayerDirection();
};

