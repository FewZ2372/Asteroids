#include "LaserBeams.h"

void setLaserBeams(int i)
{
	lasers[i].rec.x = spaceShip.rec.x;
	lasers[i].rec.y = spaceShip.rec.y;
	lasers[i].rec.width = 10;
	lasers[i].rec.height = 10;
	lasers[i].speed = 900;
	lasers[i].radius = 10;
	lasers[i].lifeSpan = 1.5f;
	lasers[i].currentLife = lasers[i].lifeSpan;
	lasers[i].isLoaded = true;
}

void laserBeamMovement()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		for (int i = 0; i < maxBullets; i++)
		{

			if (!lasers[i].isLoaded)
			{
				continue;
			}

			lasers[i].rec.x = spaceShip.rec.x;
			lasers[i].rec.y = spaceShip.rec.y;
			Vector2 moveDir = { (float)GetMouseX(), (float)GetMouseY() };

			moveDir = normalizeVector({ moveDir.x - lasers[i].rec.x, moveDir.y - lasers[i].rec.y });
			lasers[i].direction = moveDir;

			lasers[i].isLoaded = false;

			break;
		}
	}

	for (int i = 0; i < maxBullets; i++)
	{
		lasers[i].currentLife -= GetFrameTime();
		moveLaserBeam(i);

		if (lasers[i].currentLife <= 0)
		{
			setLaserBeams(i);
		}
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
	else if (lasers[i].rec.x <= 0)
	{
		lasers[i].rec.x = GetScreenWidth();
	}

	if (lasers[i].rec.y >= GetScreenHeight())
	{
		lasers[i].rec.y = 0;
	}
	else if (lasers[i].rec.y <= 0)
	{
		lasers[i].rec.y = GetScreenHeight();
	}

}