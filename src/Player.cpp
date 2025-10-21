#include "Player.h"
#include <raylib.h>
#include "Vector2d.h"



void Player::Move()
{
	//Left, Up, Right, Down. Direction player moves in
	int directions[4] = { 1, 2, 3, 4 };
	//Decide player direction
	Vector2d offsetPosition{ 0.f, 0.f };

	if (IsKeyDown(KEY_A))
	{
		currentDirection = directions[0];
	}
	if (IsKeyDown(KEY_W))
	{
		currentDirection = directions[1];
	}
	if (IsKeyDown(KEY_D))
	{
		currentDirection = directions[2];
	}
	if (IsKeyDown(KEY_S))
	{
		currentDirection = directions[3];
	}

	//Actually moving
	switch (currentDirection)
	{
	case 1:
		offsetPosition.x -= 1;
		break;
	case 2:
		offsetPosition.y -= 1;
		break;
	case 3:
		offsetPosition.x += 1;
		break;
	case 4:
		offsetPosition.y += 1;
	}

	offsetPosition = offsetPosition.NormalizeVector();

	position = position.SetVectorOffset(offsetPosition.ScaleVector(playerSpeed * GetFrameTime()));
}

void Player::Draw(Vector2d aimDirection)
{
	DrawCircle(position.x, position.y, size, YELLOW);
	DrawLine(position.x, position.y, position.x + aimDirection.x * 30.f,
		position.y + aimDirection.y * 30.f, GREEN);
}

Vector2d Player::PlayerDirection()
{
	Vector2d lookingDirection{};

	if (position.x > 0)
	{
		lookingDirection = { -1.f, 0.f };
	}
	if (position.x < 0)
	{
		lookingDirection = { 1.f, 0.f };
	}
	if (position.y > 0)
	{
		lookingDirection = { 0.f, -1.f };
	}
	if (position.y < 0)
	{
		lookingDirection = { 0.f, 1.f };
	}

	return lookingDirection;
}
