#include <raylib.h>
#include "Vector2d.h"
#include "Player.h"
#include "Wall.h"
#include <iostream>
#include <string>
#include "Enemy.h"

using namespace std;


int main()
{
	int screenWidth = 1600;
	int screenHeight = 1024;
	int currentLevel = 1;
	bool gameRunning = true;


	float halfScreenWidth = (float)(screenWidth / 2);
	float halfScreenHeight = (float)(screenHeight / 2);

	// Player Setup
	Player player;
	player.position = { halfScreenWidth, halfScreenHeight };

	// Enemy Setip
	Enemy enemy;
	enemy.position = { 200, 200 };


	//Window Setup
	InitWindow(screenWidth, screenHeight, "Cheese Wheel Man");
	SetTargetFPS(60);

	//Wall Setup
	Wall wall;
	
	//Vector Setup
	Vector2d vector2d;

	
	// Changing containters
	Wall coinArray[3];



	while (!WindowShouldClose())
	{

		//Movement

		player.Move();


		//Drawing
		BeginDrawing();
		ClearBackground(BLACK);

		if (gameRunning == true)
		{
			//Setting up debug lines from player to wall (Note, change i < x and wallArray[x] to match number of walls.)
			Wall wallArray[3];
			wallArray[0].DrawnWall(20, 20, 600, 20, WHITE);
			wallArray[1].DrawnWall(50, 50, 10, 100, WHITE);
			//wallArray[2].DrawnWall(70, 70, 100, 900, WHITE);




			player.Update();

			wall.DrawMaze(player);
			if (wall.DrawMaze(player) == true)
			{
				player.currentDirection = { 0.f, 0.f };
			}


			for (int i = 0; i < 3; i++)
			{
				if (wallArray[i].WallToObject(player.colissionPoint) == true)
				{
					player.currentDirection = { 0.f, 0.f };
				}
			}

			for (int i = 0; i < 3; i++)
			{
				if (coinArray[i].isActive == true)
				{
					coinArray[0].DrawnWall(100, 100, 20, 20, YELLOW);
					coinArray[1].DrawnWall(760, 100, 20, 20, YELLOW);
					coinArray[2].DrawnWall(1000, 450, 20, 20, YELLOW);


					if (coinArray[i].WallToObject(player.colissionPoint) == true)
					{
						player.coinsCollected += 1;
						coinArray[i].isActive = false;
						cout << player.coinsCollected;
					}

				}
			}
			enemy.pointList[0] = { 200, 200, };
			enemy.pointList[1] = { 600, 200 };
			enemy.pointList[2] = { 400, 400 };

			enemy.Patrol();


			enemy.HitPlayer(player);

			//Resets level and adds dificulty once we get enemies. We *could* make this a function but it's only called once in the whole game.
			//If we added different lose or level complete conditions then we could shorten this into a du

			if (player.coinsCollected == 3)
			{
				currentLevel += 1;
				for (int i = 0; i < 3; i++)
				{
					coinArray[i].isActive = true;
				}
				player.position = { halfScreenWidth, halfScreenHeight };
				player.coinsCollected = 0;
				player.currentDirection = { 0.f, 0.f };
				enemy.size += 5.f;
				enemy.speedMulti += 0.2;
			}
			if (enemy.HitPlayer(player) == true)
			{
				//"gameRunning" Bool checks if the 
				gameRunning = false;
			}

			string levelString = to_string(currentLevel);
			string levelText = "Level: " + levelString;
			DrawText(levelText.c_str(), 50, 10, 60, PURPLE);
		}

		else
		{
			string levelString = to_string(currentLevel);
			string loseText = "You Lost! You got to Level: " + levelString + "\n Press 'Space' to restart!";
			DrawText(loseText.c_str(), 350, 400, 60, PURPLE);
			if (IsKeyPressed(KEY_SPACE))
			{
				currentLevel = 1;
				enemy.size = 20;
				enemy.speedMulti = 1;
				player.position = { halfScreenWidth, halfScreenHeight };
				player.coinsCollected = 0;
				player.currentDirection = { 0.f, 0.f };
				for (int i = 0; i < 3; i++)
				{
					coinArray[i].isActive = true;
				}
				gameRunning = true;
			}
		}
		

		EndDrawing();
	}

	CloseWindow();
	return 0;
}