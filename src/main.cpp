#include <raylib.h>
#include "Vector2d.h"
#include "Player.h"

int main()
{
	int screenWidth = 1600;
	int screenHeight = 1024;

	float halfScreenWidth = (float)(screenWidth / 2);
	float halfScreenHeight = (float)(screenHeight / 2);

	// Player Setup
	Player player;
	player.position = { halfScreenWidth, halfScreenHeight };


	InitWindow(screenWidth, screenHeight, "Cheese Wheel Man");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		Vector2d aimDirection = player.PlayerDirection();
		//Updates

		//Movement
		player.Move();

		//Drawing
		BeginDrawing();
		ClearBackground(BLACK);

		player.Draw(aimDirection);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}