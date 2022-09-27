#include "SpaceShip.h"

float getVectorMagnitude(Vector2 vec)
{
	return sqrtf(powf(vec.x, 2) + powf(vec.y, 2));
}

Vector2 normalizeVector(Vector2 vec)
{
	float mag = getVectorMagnitude(vec);

	return { vec.x / mag, vec.y / mag };
}


void setSpaceship()
{
	spaceShip.rec.width = 40;
	spaceShip.rec.height = 80;
	spaceShip.rec.y = GetScreenHeight() / 2 - spaceShip.rec.height / 2;
	spaceShip.rec.x = GetScreenWidth() / 2 - spaceShip.rec.width / 2;
	spaceShip.lives = 4;
	spaceShip.maxSpeed = 150;
}

void spaceShipMovement()
{

	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
	{

		Vector2 moveDir = GetMousePosition();
		moveDir.x -= spaceShip.rec.x;
		moveDir.y -= spaceShip.rec.y;


		

	}
}

void xlr8SpaceShip()
{




}