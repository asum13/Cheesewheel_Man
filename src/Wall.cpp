#include "Wall.h"
#include "Player.h"
#include <raylib.h>
#include <iostream>
using namespace std;

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

bool Wall::DrawMaze(Player player)
{
	float  S = GetScreenWidth() / 20; // Square size
	Wall maze[100];

	//Border Walls
	maze[1].DrawnWall(0, 0,  S * 20,  S * 1, WHITE);
	maze[2].DrawnWall(0, 0,  S * 1,  S * 20, WHITE);
	maze[3].DrawnWall( S * 19, 0,  S * 1,  S * 20, WHITE);
	maze[4].DrawnWall(0, GetScreenHeight() - S * 1,  S * 20,  S * 1, WHITE);

	//Top Line below border
	maze[5].DrawnWall(0, S * 2,  S * 7,  S * 1, WHITE);
	maze[6].DrawnWall(S * 9, S * 2,  S * 9,  S * 1, WHITE);

	maze[7].DrawnWall(S * 7, S * 2,  S * 1,  S * 7, WHITE);
	maze[8].DrawnWall(S * 17, S * 4,  S * 3,  S * 1, WHITE);

	maze[9].DrawnWall( S * 15, S * 3,  S * 1,  S * 4, WHITE);
	
	maze[10].DrawnWall(S * 7, S * 4,  S * 4,  S * 1, WHITE);
	maze[11].DrawnWall(S * 12, S * 4,  S * 4,  S * 1, WHITE);

	maze[12].DrawnWall(S * 7, S * 7,  S * 7,  S * 1, WHITE);

	maze[13].DrawnWall(S * 2, S * 5,  S * 3,  S * 1, WHITE);
	maze[14].DrawnWall(S * 1, S * 8,  S * 3,  S * 1, WHITE);
	maze[15].DrawnWall(S * 5, S * 5,  S * 1,  S * 3, WHITE);

	maze[16].DrawnWall(S * 12, S * 10,  S * 1,  S * 4, WHITE);
	maze[17].DrawnWall(S * 4, S * 10,  S * 1,  S * 4, WHITE);
	
	maze[18].DrawnWall(S * 15, S * 8,  S * 4,  S * 1, WHITE);

	for (int i = 0; i < 100; i++)
	{
		if (maze[i].WallToObject(player.colissionPoint) == true)
		{
			return true;
		}
	}
}

