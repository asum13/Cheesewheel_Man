#include "Wall.h"
#include <raylib.h>

void Wall::DrawnWall(int xPos, int yPos, int width, int length)
{
	DrawRectangle(xPos, yPos, width, length, WHITE);
	Vector2d wallPlacement = { xPos, yPos };
	wallPlacement = wallPos;
	xWidthLow = xPos - (width/2);
	xWidthHigh = xPos + (width / 2);
	yLengthLow = yPos - (length / 2);
	yLengthHigh = yPos + (length / 2);
}
