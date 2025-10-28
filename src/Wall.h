#pragma once
#include "Vector2d.h"

class Wall
{
public:	
	float xWidthLow = 0.f;
	float xWidthHigh = 0.f;
	float yLengthLow = 0.f;	
	float yLengthHigh = 0.f;
	bool isWall = true;
	void DrawnWall(int xPos, int yPos, int width, int length);
	float xPosition = 0.f;
	float yPosition = 0.f;
	Vector2d wallPos = { xPosition, yPosition };

};

