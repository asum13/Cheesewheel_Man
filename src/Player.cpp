#include "Player.h"
#include <raylib.h>
#include "Vector2d.h"
#include <iostream>
using namespace std;
Vector2d vector2d;


void Player::Move()
{
	//Decide player direction

	if (IsKeyPressed(KEY_A))
	{
		currentDirection = {-1.f, 0.f};
		lookingDirection = { -1.f, 0.f };
	}
	if (IsKeyPressed(KEY_W))
	{
		currentDirection = { 0.f, -1.f };
		lookingDirection = { 0.f, -1.f };
	}
	if (IsKeyPressed(KEY_D))
	{
		currentDirection = { 1.f, 0.f };
		lookingDirection = { 1.f, 0.f };
	}
	if (IsKeyPressed(KEY_S))
	{
		currentDirection = { 0.f, 1.f };
		lookingDirection = { 0.f, 1.f };
	}

	currentDirection = currentDirection.NormalizeVector();

	position = position.SetVectorOffset(currentDirection.ScaleVector(playerSpeed * GetFrameTime()));

}



void Player::Draw(Vector2d aimDirection)
{
	DrawCircle(position.x, position.y, size, YELLOW);
	DrawLine(position.x, position.y, position.x + aimDirection.x * size,
	position.y + aimDirection.y * size, GREEN);

	Vector2d pointPoint = vector2d.FindPoint(aimDirection);
	float xColitionCheck = pointPoint.x + position.x;
	float yColitionCheck = pointPoint.y + position.y;
	colitionPoint = { xColitionCheck, yColitionCheck };

	DrawCircle(xColitionCheck, yColitionCheck, 2.f, RED);
	
}
