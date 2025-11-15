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
	
	//Vector Setup
	Vector2d vector2d;

	

	Wall coinArray[3];


	while (!WindowShouldClose())
	{

		//Movement

		player.Move();


		//Drawing
		BeginDrawing();
		ClearBackground(BLACK);

		//Setting up debug lines from player to wall (Note, change i < x and wallArray[x] to match number of walls.)
		Wall wallArray[3];
		wallArray[0].DrawnWall(20, 20, 600, 20, WHITE);
		wallArray[1].DrawnWall(50, 50, 10, 100, WHITE);
		wallArray[2].DrawnWall(70, 70, 100, 900, WHITE);
		
		

		player.Draw();

		for (int i = 0; i < 3; i++)
		{
			if (wallArray[i].WallToObject(player.colissionPoint) == true)
			{
				player.currentDirection = { 0.f, 0.f };
				player.lookingDirection = { 0.f, 0.f };
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (coinArray[i].isActive == true)
			{
				coinArray[0].DrawnWall(380, 200, 20, 20, YELLOW);
				coinArray[1].DrawnWall(760, 100, 20, 20, YELLOW);
				coinArray[2].DrawnWall(1200, 400, 20, 20, YELLOW);


				if (coinArray[i].WallToObject(player.colissionPoint) == true)
				{
					player.coinsCollected += 1;
					coinArray[i].isActive = false;
					cout << player.coinsCollected;
				}

			}
		}


		EndDrawing();
	}

	CloseWindow();
	return 0;
}