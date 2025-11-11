#include "Wall.h"
#include "Player.h"
#include <raylib.h>
#include <iostream>
using namespace std;

Player player;

Vector2d Wall::DrawnWall(float xPos, float yPos, int width, int length)
{
	DrawRectangle(xPos, yPos, width, length, WHITE);
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

void Wall::WallToObject(Vector2d object)
{
	DrawLine(wallPosition.x, wallPosition.y, object.x, object.y, ORANGE);

	cout << object.x - wallLeftPos << "\n";

	
	if (((object.x - wallRight) <= 0) && ((object.x - wallLeftPos) > 0))
	{
		object = { 0.f, 0.f };
		player.currentDirection = object;
		player.lookingDirection = object;
	}
}

