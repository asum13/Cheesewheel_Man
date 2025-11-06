#include "Wall.h"
#include <raylib.h>



Vector2d Wall::DrawnWall(float xPos, float yPos, int width, int length)
{
	DrawRectangle(xPos, yPos, width, length, WHITE);
	wallXPos = (xPos + (width / 2));
	wallYPos = (yPos + (length / 2));
	Vector2d wallPoint = { wallXPos, wallYPos };
	DrawCircle(wallPoint.x, wallPoint.y, 3, RED);
	wallPosition = wallPoint;
	wallWidth = width;
	wallLength = length;
	return wallPosition;
}


