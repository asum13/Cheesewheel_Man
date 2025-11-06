#include "Vector2d.h"
#include <raylib.h>
#include <math.h>
#include "Player.h"
Player player;

float Vector2d::CalculateMagnitude()
{
	float magniSqur = x * x + y * y;
	float magnitude = sqrtf(magniSqur);
	return magnitude;
}

Vector2d Vector2d::SetVectorOffset(Vector2d inVectorToAdd)
{
	float outVectorX = x + inVectorToAdd.x;
	float outVectorY = y + inVectorToAdd.y;
	Vector2d outVector{ outVectorX, outVectorY };

	return outVector;
}

Vector2d Vector2d::ScaleVector(float inScalar)
{
	float scaledXVector = x * inScalar;
	float scaledYVector = y * inScalar;
	Vector2d scaledVector{ scaledXVector, scaledYVector };

	return scaledVector;
}

Vector2d Vector2d::VectorTowardsTarget(Vector2d inTargetVector)
{
	float targetedXVector = inTargetVector.x - x;
	float targetedYVector = inTargetVector.y - y;
	Vector2d targetedVector{ targetedXVector , targetedYVector };

	return targetedVector;
}

float Vector2d::DistanceToTarget(Vector2d inTargetedVector)
{
	Vector2d targetedVector = VectorTowardsTarget(inTargetedVector);
	float distanceToTargetedVector = targetedVector.CalculateMagnitude();

	return distanceToTargetedVector;
}

Vector2d Vector2d::NormalizeVector()
{
	if (CalculateMagnitude() == 0)
	{
		return { 0, 0 };
	}

	float normalizedXVector = x / CalculateMagnitude();
	float normalizedYVector = y / CalculateMagnitude();
	Vector2d normalizedVector{ normalizedXVector,normalizedYVector };

	return normalizedVector;
}

Vector2d Vector2d::FindPoint(Vector2d aimDirection)
{
	float xPoint = player.position.x + aimDirection.x * player.size;
	float yPoint = player.position.y + aimDirection.y * player.size;
	Vector2d pointPoint = { xPoint, yPoint };
	return pointPoint;
}


