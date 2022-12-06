#include "SpaceShip.h"


void setSpaceship()
{
	spaceShip.rec.width = 20;
	spaceShip.rec.height = 40;
	spaceShip.rec.y = GetScreenHeight() / 2 - spaceShip.rec.height / 2;
	spaceShip.rec.x = GetScreenWidth() / 2 - spaceShip.rec.width / 2;
	spaceShip.speed = 30;
	spaceShip.lives = 3;
	spaceShip.maxSpeed = 50;
	spaceShip.bullets = 0;
	spaceShip.textureIdle = LoadTexture("res/SpaceShipIdle.png");
	spaceShip.textureMoving = LoadTexture("res/SpaceShipMoving.png");

}

void spaceShipMovement()
{
	float axisX = 0;
	float axisY = 0;

	if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
	{
		Vector2 moveDir = { GetMouseX(), GetMouseY() };

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