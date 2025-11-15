#include "Wall.h"
#include "Player.h"
#include <raylib.h>
#include <iostream>
using namespace std;

Player player;

Vector2d Wall::DrawnWall(float xPos, float yPos, int width, int length, Color color)
{
	if (isActive == true)
	{
		DrawRectangle(xPos, yPos, width, length, color);
	
		wallWidth = width;
		wallLength = length;

		wallRight = xPos + width;
		wallDown = yPos + length;
		wallLeftPos = xPos;
		wallUpPos = yPos;

		Vector2d wallPoint = { wallLeftPos, wallUpPos };
		wallPosition = wallPoint;
		DrawCircle(wallPoint.x, wallPoint.y, 3, RED);
	

		return wallPosition;
	}
}

bool Wall::WallToObject(Vector2d object)
{
	
	if (((object.x - wallRight) <= 0) && ((object.x - wallLeftPos) > 0))
	{
		if (((object.y - wallDown) <= 0) && ((object.y - wallUpPos) > 0))
		{
			return true;
		}
	}


	return false;
}

