#pragma once
#include "Vector2d.h"
#include "Player.h"

class Enemy
{
public:
	Vector2d position;
	Vector2d pointList[3];
	Vector2d point1 = { 0, 100, };
	Vector2d point2 = { 1400, 200, };
	Vector2d point3 = { 700, 1000, };
	float size = 20.f;
	float speedMulti = 0.4;
	int currentPatrol = 0;
	int goingPatrol = 0;
	Vector2d distance = {0, 0 };
	bool reachedPoint = true;
	void Patrol();
	void NextPath();
	void CalculateVec();
	bool HitPlayer(Player player);
};

