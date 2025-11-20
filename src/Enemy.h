#pragma once
#include "Vector2d.h"
#include "Player.h"

class Enemy
{
public:
	Vector2d position;
	Vector2d pointList[3];
	float size = 20.f;
	float speedMulti = 1.f;
	int currentPatrol = 0;
	int goingPatrol = 0;
	Vector2d distance = {0, 0 };
	bool reachedPoint = true;
	void Patrol();
	void NextPath();
	void CalculateVec();
	bool HitPlayer(Player player);
};

