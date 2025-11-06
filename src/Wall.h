#pragma once
#include "Vector2d.h"

class Wall
{
public:
	float wallXPos = 0.f;
	float wallYPos = 0.f;
	int wallWidth = 0;
	int wallLength = 0;
	Vector2d wallPosition = { wallXPos, wallYPos };
	Vector2d DrawnWall(float xPos, float yPos, int width, int length);
};;
