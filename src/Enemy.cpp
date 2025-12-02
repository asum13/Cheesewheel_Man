#include "Enemy.h"
#include <cstdlib>
#include <raylib.h>
#include "Vector2d.h"
#include <iostream>
#include "Player.h"

using namespace std;

void Enemy::Patrol()
{
	DrawCircle(position.x, position.y, size, RED);
	if (reachedPoint == true)
	{
		cout << "made it here" << endl;
		currentPatrol = goingPatrol;
		NextPath();
		CalculateVec();
		reachedPoint = false;
	}

	position = position.SetVectorOffset(distance.ScaleVector(speedMulti * GetFrameTime()));

	if (position.DistanceToTarget(pointList[goingPatrol]) < 30)
	{
		position = pointList[goingPatrol];
		reachedPoint = true;
	}
	
}



void Enemy::NextPath()
{
	int newPath = rand() % 6;
	if (newPath == currentPatrol)
	{
		NextPath();
	}
	else
	{
		goingPatrol = newPath;
		reachedPoint = false;
	}
}


void Enemy::CalculateVec()
{
	distance = { pointList[goingPatrol].x - position.x ,  pointList[goingPatrol].y - position.y };
}
bool Enemy::HitPlayer(Player player)
{
	if (position.DistanceToTarget(player.position) < size + player.size)
	{
		return true;
	}
	else
	{
		return false;
	}
}
;