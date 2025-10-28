#pragma once
#include "Vector2d.h"

class Wall
{
public:
	float xPosition = 0.f;
	float yPosition = 0.f;
	bool isWall = true;
	void DrawnWall(int xPos, int yPos, int width, int length);
	Vector2d wallPos = { xPosition, yPosition };
	float xWidth = 0.f;
	float yLength = 0.f;
};

