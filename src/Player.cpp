#include "Player.h"
#include "Vector2d.h"

#include <raylib.h>
#include <iostream>

using namespace std;
Vector2d vector2d;


void Player::Move()
{
	//Decide player direction

	if (IsKeyPressed(KEY_A) && currentDirection.x != 1.f)
	{
		currentDirection = {-1.f, 0.f};
	}
	if (IsKeyPressed(KEY_W) && currentDirection.y != 1.f)
	{
		currentDirection = { 0.f, -1.f };
	}
	if (IsKeyPressed(KEY_D) && currentDirection.x != -1.f)
	{
		currentDirection = { 1.f, 0.f };
	}
	if (IsKeyPressed(KEY_S) && currentDirection.y != -1.f)
	{
		currentDirection = { 0.f, 1.f };
	}

	currentDirection = currentDirection.NormalizeVector();

	position = position.SetVectorOffset(currentDirection.ScaleVector(playerSpeed * GetFrameTime()));

}



void Player::Update()
{
	DrawCircle(position.x, position.y, size, YELLOW);
	DrawLine(position.x, position.y, position.x + currentDirection.x * size,
		position.y + currentDirection.y * size, GREEN);

	Vector2d pointPoint = vector2d.FindPoint(currentDirection, position, size);
	float xColitionCheck = pointPoint.x;
	float yColitionCheck = pointPoint.y;
	colissionPoint = { xColitionCheck, yColitionCheck };

	DrawCircle(xColitionCheck, yColitionCheck, 2.f, RED);
}


//void Player::PlayerToObject(Vector2d object)
//{
//	DrawLine(object.x, object.y, colitionPoint.x, colitionPoint.y, ORANGE);
//
//
//	//Make checks for the side and top locations
//	if (colitionPoint.DistanceToTarget(object) < (wall.wallWidth || wall.wallLength))
//	{
//		DrawLine(object.x, object.y, colitionPoint.x, colitionPoint.y, PURPLE);
//		currentDirection = { 0.f, 0.f };
//		lookingDirection = { 0.f, 0.f };
//
//	}
//}
