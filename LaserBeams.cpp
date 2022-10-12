#include "LaserBeams.h"

void setLaserBeams(int i)
{
	lasers[i].rec.x = spaceShip.rec.x;
	lasers[i].rec.y = spaceShip.rec.y;
	lasers[i].rec.width = 10;
	lasers[i].rec.height = 10;
	lasers[i].speed = 600;
	lasers[i].radius = 10;
}

void laserBeamMovement()
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			lasers[i].isLoaded = true;

			setLaserBeams(i);
			Vector2 moveDir = { (float)GetMouseX(), (float)GetMouseY() };

			moveDir = normalizeVector({ moveDir.x - lasers[i].rec.x, moveDir.y - lasers[i].rec.y });

			lasers[i].direction = moveDir;
		}
		moveLaserBeam(i);
	}
}

void moveLaserBeam(int i)
{
	lasers[i].rec.x += lasers[i].direction.x * lasers[i].speed * GetFrameTime();
	lasers[i].rec.y += lasers[i].direction.y * lasers[i].speed * GetFrameTime();

	if (lasers[i].rec.x >= GetScreenWidth())
	{
		lasers[i].rec.x = 0;
	}
	else if (spaceShip.rec.x <= 0)
	{
		lasers[i].rec.x = GetScreenWidth();
	}

	if (lasers[i].rec.y >= GetScreenHeight())
	{
		lasers[i].rec.y = 0;
	}
	else if (spaceShip.rec.y <= 0)
	{
		lasers[i].rec.y = GetScreenHeight();
	}

}