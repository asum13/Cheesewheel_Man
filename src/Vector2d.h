#pragma once
class Vector2d
{
public:

	float x;
	float y;

	float CalculateMagnitude();;

	Vector2d SetVectorOffset(Vector2d inVectorToAdd);;

	Vector2d ScaleVector(float inScalar);;

	Vector2d NormalizeVector();

	Vector2d FindPoint(Vector2d aimDirection);
	Vector2d VectorTowardsTarget(Vector2d inTargetVector);
	float DistanceToTarget(Vector2d inTargetedVector);
	;

};

