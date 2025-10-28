#include <raylib.h>
#include "Vector2d.h"
#include "Player.h"
#include "Wall.h"
#include <iostream>
using namespace std;


int main()
{
	int screenWidth = 1600;
	int screenHeight = 1024;

	float halfScreenWidth = (float)(screenWidth / 2);
	float halfScreenHeight = (float)(screenHeight / 2);

	// Player Setup
	Player player;
	player.position = { halfScreenWidth, halfScreenHeight };

	//Window Setup
	InitWindow(screenWidth, screenHeight, "Cheese Wheel Man");
	SetTargetFPS(60);

	//Wall Setup
	Wall wall;




	



	while (!WindowShouldClose())
	{

		//Movement

		player.Move();



		//Drawing
		BeginDrawing();
		ClearBackground(BLACK);

		wall.DrawnWall(200, 200, 600, 20);

		player.Draw(player.lookingDirection);

		if (wall.isWall == true)
		{
			if (player.colitionPoint.DistanceToTarget(wall.wallPos) < (wall.xWidthHigh) || player.colitionPoint.DistanceToTarget(wall.wallPos) > (wall.xWidthLow))
			{
				player.currentDirection = { 0.f, 0.f };
				player.lookingDirection = { 0.f, 0.f };
				cout << "It's working somehow";
			}
			if (player.colitionPoint.DistanceToTarget(wall.wallPos) < (wall.yLengthHigh) || player.colitionPoint.DistanceToTarget(wall.wallPos) > (wall.yLengthLow))
			{
				player.currentDirection = { 0.f, 0.f };
				player.lookingDirection = { 0.f, 0.f };
				cout << "somehow it's working. ";
			}
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}