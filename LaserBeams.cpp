#include "LaserBeams.h"

void setLaserBeams()
{
	for (int i = 0; i < maxBullets; i++)
	{
		lasers[i].pos.x = spaceShip.rec.x;
		lasers[i].pos.y = spaceShip.rec.y;
		lasers[i].speed = 600;
		lasers[i].radius = 3;
		lasers[i].lifeSpan = 1.5f;
		lasers[i].isLoaded = true;
		lasers[i].laserSound = LoadSound("res/LaserBeam.wav");
	}
}

void laserBeamMovement()
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (lasers[i].isLoaded == true)
		{
			lasers[i].pos.x = spaceShip.rec.x;
			lasers[i].pos.y = spaceShip.rec.y;
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && lasers[i].isLoaded == true)
		{
			lasers[i].isLoaded = false;
			Vector2 moveDir = { GetMouseX(), GetMouseY() };
			moveDir = normalizeVector({ moveDir.x - lasers[i].pos.x, moveDir.y - lasers[i].pos.y });
			lasers[i].direction = moveDir;

			break;
		}
		if (lasers[i].isLoaded == false)
		{
			moveLaserBeam(i);
			lasers[i].lifeSpan -= GetFrameTime();

			if (lasers[i].lifeSpan <= 0)
			{
				lasers[i].lifeSpan = 3.0f;
				lasers[i].isLoaded = true;
			}
		}
	}
}

void moveLaserBeam(int i)
{
	lasers[i].pos.x += lasers[i].direction.x * lasers[i].speed * GetFrameTime();
	lasers[i].pos.y += lasers[i].direction.y * lasers[i].speed * GetFrameTime();

	if (lasers[i].pos.x > GetScreenWidth())
	{
		lasers[i].pos.x = 0;
	}
	if (lasers[i].pos.x < 0)
	{
		lasers[i].pos.x = GetScreenWidth();
	}
	if (lasers[i].pos.y > GetScreenHeight())
	{
		lasers[i].pos.y = 0;
	}
	else if (lasers[i].pos.y < 0)
	{
		lasers[i].pos.y = GetScreenHeight();
	}

}

void drawLasers()
{
	for (int i = 0; i < maxBullets; i++)
	{
		DrawCircle(lasers[i].pos.x, lasers[i].pos.y, lasers[i].radius, RED);
	}
}