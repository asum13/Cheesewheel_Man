#pragma once
#include "Vector2d.h"

class Wall
{
public:
	float wallLeftPos = 0.f;
	float wallUpPos = 0.f;
	float wallRight = 0.f;
	float wallDown = 0.f;
	int wallWidth = 0;
	int wallLength = 0;
	Vector2d wallPosition = { wallLeftPos, wallUpPos };
	Vector2d DrawnWall(float xPos, float yPos, int width, int length);
	void WallToObject(Vector2d object);
};;
