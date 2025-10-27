#include <raylib.h>
#include "Vector2d.h"
#include "Player.h"
#include "Wall.h"

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

		wall.DrawnWall(100, 100, 200, 10);

		player.Draw(player.lookingDirection);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}