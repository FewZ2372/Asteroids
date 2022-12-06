#include "space_ship.h"

namespace FewZ
{
	SpaceShip spaceShip;	
	
Sound explosionSound;

	void setSpaceship()
	{
		spaceShip.rec.width = 20;
		spaceShip.rec.height = 20;
		spaceShip.direction.x = 0;
		spaceShip.direction.y = 0;
		spaceShip.rec.y = GetScreenHeight() / 2 - spaceShip.rec.height / 2;
		spaceShip.rec.x = GetScreenWidth() / 2 - spaceShip.rec.width / 2;
		spaceShip.speed = 30;
		spaceShip.lives = 3;
		spaceShip.maxSpeed = 50;
		spaceShip.points = 105;

	}

	void spaceShipMovement()
	{
		float axisX = 0;
		float axisY = 0;

		Vector2 rotation = { GetMouseX() - spaceShip.rec.x, GetMouseY() - spaceShip.rec.y };

		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
		{
			DrawTexturePro(spaceShip.textureMoving, { -10 , 0, 200, 200 }, { spaceShip.rec.x, spaceShip.rec.y, 200, 200 }, { 85, 85 }, getRotation(rotation) - 90, WHITE);

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
}