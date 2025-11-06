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

	



	while (!WindowShouldClose())
	{

		//Movement

		player.Move();


		//Drawing
		BeginDrawing();
		ClearBackground(BLACK);

		//Setting up debug lines from player to wall (Note, change i < x and wallArray[x] to match number of walls.)
		Vector2d wallArray[3] = { wall.DrawnWall(20, 20, 600, 20), wall.DrawnWall(50,50,10,100), wall.DrawnWall(70, 70, 100, 900)};

		for (int i = 0; i < 3; i++)
		{
			player.PlayerToObject(wallArray[i]);
		}

		player.Draw(player.lookingDirection);




		EndDrawing();
	}

	CloseWindow();
	return 0;
}