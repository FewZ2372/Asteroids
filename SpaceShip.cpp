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
	spaceShip.speed = 30;
	spaceShip.lives = 4;
	spaceShip.maxSpeed = 80;
}

void spaceShipMovement()
{
	float axisX = 0;
	float axisY = 0;

	if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
	{
		Vector2 moveDir = { (float)GetMouseX(), (float)GetMouseY() };

		moveDir = normalizeVector({ moveDir.x - spaceShip.rec.x, moveDir.y - spaceShip.rec.y });

		axisX = moveDir.x;
		axisY = moveDir.y;

	}

	accelerateSpaceShip(axisX, axisY, spaceShip);
}
void accelerateSpaceShip(float axisX, float axisY, SpaceShip& spaceShip)
{
	Vector2 newVel = spaceShip.direction;

	newVel.x += axisX * spaceShip.speed * GetFrameTime();
	newVel.y += axisY * spaceShip.speed * GetFrameTime();

	if (newVel.x <= spaceShip.maxSpeed)
	{
		spaceShip.direction.x = newVel.x;
	}
	if (newVel.y <= spaceShip.maxSpeed)
	{
		spaceShip.direction.y = newVel.y;
	}

	moveShip();
}

void moveShip()
{
	spaceShip.rec.x += spaceShip.direction.x * spaceShip.speed * GetFrameTime();
	spaceShip.rec.y += spaceShip.direction.y * spaceShip.speed * GetFrameTime();

	if (spaceShip.rec.x >= GetScreenWidth())
	{
		spaceShip.rec.x = 0;
	}
	else if (spaceShip.rec.x <= 0)
	{
		spaceShip.rec.x = GetScreenWidth();
	}

	if (spaceShip.rec.y >= GetScreenHeight())
	{
		spaceShip.rec.y = 0;
	}
	else if (spaceShip.rec.y <= 0)
	{
		spaceShip.rec.y = GetScreenHeight();
	}
}

float getRotation(Vector2 dir)
{
	float rot = atan(dir.y / dir.x);

	rot = rot * 180 / PI;

	if (dir.x < 0)
	{
		rot += 180;
	}

	rot += 90;

	return rot;
}