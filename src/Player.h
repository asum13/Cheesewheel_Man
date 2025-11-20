#pragma once
#include "Vector2d.h"
class Player
{
public:
	Vector2d position;
	float playerSpeed = 200.f;
	float size = 30.f;
	Vector2d currentDirection = { 0.f, 0.f };
	Vector2d lookingDirection{ 0.f, 0.f };
	Vector2d colissionPoint = { 0.f, 0.f };
	bool gotHit = false;

	int coinsCollected = 0;

	void Move();

	void Update();

	//void PlayerToObject(Vector2d object);

};

