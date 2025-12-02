#include <raylib.h>
#include "Vector2d.h"
#include "Player.h"
#include "Wall.h"
#include <iostream>
#include <string>
#include "Enemy.h"
#include <cstdlib>

using namespace std;


int main()
{
	int screenWidth = 1600;
	int screenHeight = 1024;
	int currentLevel = 1;
	bool gameRunning = true;
	srand(time(0));


	float halfScreenWidth = (float)(screenWidth / 2);
	float halfScreenHeight = (float)(screenHeight / 2);

	// Player Setup
	Player player;
	player.position = { halfScreenWidth - 100.f, halfScreenHeight - 50.f};

	// Enemy Setip
	Enemy enemy;
	enemy.position = { 0, 100 };
	//int negRandomizer = 0;


	//Window Setup
	InitWindow(screenWidth, screenHeight, "Cheese Wheel Man");
	SetTargetFPS(60);

	//Wall Setup
	Wall wall;
	
	//Vector Setup
	Vector2d vector2d;

	
	// Changing containters
	Wall coinArray[31];



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

			for (int i = 0; i < 31; i++)
			{
				if (coinArray[i].isActive == true)
				{
					coinArray[0].DrawnWall(100, 100, 30, 40, YELLOW);
					coinArray[1].DrawnWall(310, 100, 30, 40, YELLOW);
					coinArray[2].DrawnWall(500, 100, 30, 40, YELLOW);
					coinArray[3].DrawnWall(675, 100, 30, 40, YELLOW);
					coinArray[4].DrawnWall(850, 100, 30, 40, YELLOW);
					coinArray[6].DrawnWall(1250, 100, 30, 40, YELLOW);
					coinArray[7].DrawnWall(1460, 100, 30, 40, YELLOW);
					coinArray[8].DrawnWall(1460, 260, 30, 40, YELLOW);
					coinArray[5].DrawnWall(1050, 100, 30, 40, YELLOW);
					coinArray[9].DrawnWall(1310, 260, 30, 40, YELLOW);
					coinArray[10].DrawnWall(1080, 275, 30, 40, YELLOW);
					coinArray[12].DrawnWall(680, 275, 30, 40, YELLOW);
					coinArray[11].DrawnWall(905, 275, 30, 40, YELLOW);

					coinArray[13].DrawnWall(905, 450, 30, 40, YELLOW);
					coinArray[14].DrawnWall(1150, 450, 30, 40, YELLOW);

					coinArray[15].DrawnWall(110, 300, 30, 40, YELLOW);
					coinArray[16].DrawnWall(110, 550, 30, 40, YELLOW);
					coinArray[17].DrawnWall(350, 550, 30, 40, YELLOW);

					coinArray[18].DrawnWall(300, 300, 30, 40, YELLOW);
					coinArray[19].DrawnWall(510, 300, 30, 40, YELLOW);
					coinArray[20].DrawnWall(510, 500, 30, 40, YELLOW);
					coinArray[21].DrawnWall(190, 810, 30, 40, YELLOW);
					coinArray[22].DrawnWall(500, 810, 30, 40, YELLOW);
					coinArray[23].DrawnWall(700, 810, 30, 40, YELLOW);
					coinArray[24].DrawnWall(900, 810, 30, 40, YELLOW);
					coinArray[25].DrawnWall(1200, 810, 30, 40, YELLOW);
					coinArray[26].DrawnWall(1450, 810, 30, 40, YELLOW);
					coinArray[27].DrawnWall(1450, 450, 30, 40, YELLOW);
					coinArray[28].DrawnWall(1450, 580, 30, 40, YELLOW);
					coinArray[29].DrawnWall(1310, 450, 30, 40, YELLOW);
					coinArray[30].DrawnWall(1310, 580, 30, 40, YELLOW);


					


					if (coinArray[i].WallToObject(player.colissionPoint) == true)
					{
						player.coinsCollected += 1;
						coinArray[i].isActive = false;
						cout << player.coinsCollected;
					}

				}
			}
			enemy.pointList[0] = enemy.point1;
			enemy.pointList[1] = enemy.point2;
			enemy.pointList[2] = enemy.point3;
			enemy.pointList[3] = enemy.point4;
			enemy.pointList[4] = enemy.point5;
			enemy.pointList[5] = enemy.point6;

			enemy.Patrol();


			enemy.HitPlayer(player);

			//Resets level and adds dificulty once we get enemies. We *could* make this a function but it's only called once in the whole game.
			//If we added different lose or level complete conditions then we could shorten this into a du

			if (player.coinsCollected == 31)
			{
				currentLevel += 1;
				for (int i = 0; i < 31; i++)
				{
					coinArray[i].isActive = true;
				}
				player.position = { halfScreenWidth - 100.f, halfScreenHeight - 50.f };
				player.coinsCollected = 0;
				player.currentDirection = { 0.f, 0.f };
				enemy.size += 5.f;
				enemy.speedMulti += 0.2;
				//negRandomizer = rand() % 21;
				//if (negRandomizer % 2 == 0)
				//{
				//	enemy.point1.x += rand() % 51;
				//	enemy.point2.x += rand() % 51;
				//	enemy.point3.x += rand() % 51;
				//	enemy.point1.y += rand() % 51;
				//	enemy.point2.y += rand() % 51;
				//	enemy.point3.y += rand() % 51;
				//}
				//else
				//{
				//	enemy.point1.x -= rand() % 51;
				//	enemy.point2.x -= rand() % 51;
				//	enemy.point3.x -= rand() % 51;
				//	enemy.point1.y -= rand() % 51;
				//	enemy.point2.y -= rand() % 51;
				//	enemy.point3.y -= rand() % 51;
				//}
				enemy.position = enemy.pointList[enemy.currentPatrol];

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
				player.position = { halfScreenWidth - 100.f, halfScreenHeight - 50.f };
				player.coinsCollected = 0;
				player.currentDirection = { 0.f, 0.f };
				enemy.point1 = { 0, 100, };
				enemy.point2 = { 1400, 200, };
				enemy.point3 = { 700, 1000, };
				for (int i = 0; i < 31; i++)
				{
					coinArray[i].isActive = true;
				}
				enemy.position = enemy.position = enemy.pointList[enemy.currentPatrol];
				gameRunning = true;
			}
		}
		

		EndDrawing();
	}

	CloseWindow();
	return 0;
}