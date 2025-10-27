#include "Wall.h"
#include <raylib.h>

void Wall::DrawnWall(int xPos, int yPos, int width, int length)
{
	DrawRectangle(xPos, yPos, width, length, WHITE);
}
