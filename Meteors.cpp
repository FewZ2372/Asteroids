#include "Meteors.h"

void setBigMeteors()
{
	for (int i = 0; i < 15; i++)
	{
		bigMeteor[i].pos.x = rand() % 1024;
		bigMeteor[i].pos.y = rand() % 768;

		if (bigMeteor[i].pos.x < GetScreenWidth() / 3 * 2 && bigMeteor[i].pos.x < GetScreenWidth() / 3 * 1)
		{
			bigMeteor[i].pos.x = rand() % 1024;
		}
		if (bigMeteor[i].pos.y < GetScreenHeight() / 6 * 2 && bigMeteor[i].pos.y < GetScreenHeight() / 6 * 4)
		{
			bigMeteor[i].pos.y = rand() % 768;
		}

		bigMeteor[i].speed = 50;
		bigMeteor[i].radio = 10;
		bigMeteor[i].life = 1;
	}
}

void setMiddleMeteors()
{
	for (int i = 0; i < 30; i++)
	{
		middleMeteor[i].pos.x = rand() % 1024;
		middleMeteor[i].pos.y = rand() % 768;

		if (middleMeteor[i].pos.x < GetScreenWidth() / 3 * 2 && middleMeteor[i].pos.x < GetScreenWidth() / 3 * 1)
		{
			middleMeteor[i].pos.x = rand() % 1024;
		}
		if (middleMeteor[i].pos.y < GetScreenHeight() / 6 * 2 && middleMeteor[i].pos.y < GetScreenHeight() / 6 * 4)
		{
			middleMeteor[i].pos.y = rand() % 768;
		}

		middleMeteor[i].speed = 50;
		middleMeteor[i].radio = 5;
		middleMeteor[i].life = 1;
	}
}

void setLittleMeteors()
{
	for (int i = 0; i < 60; i++)
	{
		littleMeteor[i].pos.x = rand() % 1024;
		littleMeteor[i].pos.y = rand() % 768;

		if (littleMeteor[i].pos.x < GetScreenWidth() / 3 * 2 && littleMeteor[i].pos.x < GetScreenWidth() / 3 * 1)
		{
			littleMeteor[i].pos.x = rand() % 1024;
		}
		if (littleMeteor[i].pos.y < GetScreenHeight() / 6 * 2 && littleMeteor[i].pos.y < GetScreenHeight() / 6 * 4)
		{
			littleMeteor[i].pos.y = rand() % 768;
		}

		littleMeteor[i].speed = 50;
		littleMeteor[i].radio = 2;
		littleMeteor[i].life = 1;
	}
}

void drawMeteors()
{
	for (int i = 0; i < maxBigMeteors; i++)
	{
		DrawCircle(bigMeteor[i].pos.x, bigMeteor[i].pos.y, bigMeteor[i].radio, GREEN);
	}

	for (int i = 0; i < maxMidMeteors; i++)
	{
		DrawCircle(middleMeteor[i].pos.x, middleMeteor[i].pos.y, middleMeteor[i].radio, GREEN);
	}

	for (int i = 0; i < maxLittleMeteors; i++)
	{
		DrawCircle(littleMeteor[i].pos.x, littleMeteor[i].pos.y, littleMeteor[i].radio, GREEN);
	}
}

void meteorDirection()
{
	for (int i = 0; i < maxBigMeteors; i++)
	{
		bigMeteor[i].direction.x = rand() % 360;
		bigMeteor[i].direction.y = rand() % 360;

		Vector2 moveDir = { bigMeteor[i].direction.x, bigMeteor[i].direction.y };
		moveDir = normalizeVector({ moveDir.x - bigMeteor[i].pos.x, moveDir.y - bigMeteor[i].pos.y });
		bigMeteor[i].direction = moveDir;
	}

	for (int i = 0; i < maxMidMeteors; i++)
	{
		middleMeteor[i].direction.x = rand() % 360;
		middleMeteor[i].direction.y = rand() % 360;

		Vector2 moveDir = { middleMeteor[i].direction.x, middleMeteor[i].direction.y };
		moveDir = normalizeVector({ moveDir.x - middleMeteor[i].pos.x, moveDir.y - middleMeteor[i].pos.y });
		middleMeteor[i].direction = moveDir;
	}

	for (int i = 0; i < maxLittleMeteors; i++)
	{
		littleMeteor[i].direction.x = rand() % 360;
		littleMeteor[i].direction.y = rand() % 360;

		Vector2 moveDir = { littleMeteor[i].direction.x, littleMeteor[i].direction.y };
		moveDir = normalizeVector({ moveDir.x - littleMeteor[i].pos.x, moveDir.y - littleMeteor[i].pos.y });
		littleMeteor[i].direction = moveDir;
	}

	moveMeteor();
}

void moveMeteor()
{
	for (int i = 0; i < maxBigMeteors; i++)
	{
		bigMeteor[i].pos.x += bigMeteor[i].direction.x * bigMeteor[i].speed * GetFrameTime();
		bigMeteor[i].pos.y += bigMeteor[i].direction.y * bigMeteor[i].speed * GetFrameTime();

		if (bigMeteor[i].pos.x >= GetScreenWidth())
		{
			bigMeteor[i].pos.x = 0;
		}
		else if (bigMeteor[i].pos.x <= 0)
		{
			bigMeteor[i].pos.x = GetScreenWidth();
		}

		if (bigMeteor[i].pos.y >= GetScreenHeight())
		{
			bigMeteor[i].pos.y = 0;
		}
		else if (bigMeteor[i].pos.y <= 0)
		{
			bigMeteor[i].pos.y = GetScreenHeight();
		}
	}

	for (int i = 0; i < maxMidMeteors; i++)
	{
		middleMeteor[i].pos.x += middleMeteor[i].direction.x * middleMeteor[i].speed * GetFrameTime();
		middleMeteor[i].pos.y += middleMeteor[i].direction.y * middleMeteor[i].speed * GetFrameTime();

		if (middleMeteor[i].pos.x >= GetScreenWidth())
		{
			middleMeteor[i].pos.x = 0;
		}
		else if (middleMeteor[i].pos.x <= 0)
		{
			middleMeteor[i].pos.x = GetScreenWidth();
		}

		if (middleMeteor[i].pos.y >= GetScreenHeight())
		{
			middleMeteor[i].pos.y = 0;
		}
		else if (middleMeteor[i].pos.y <= 0)
		{
			middleMeteor[i].pos.y = GetScreenHeight();
		}
	}

	for (int i = 0; i < maxLittleMeteors; i++)
	{
		littleMeteor[i].pos.x += littleMeteor[i].direction.x * littleMeteor[i].speed * GetFrameTime();
		littleMeteor[i].pos.y += littleMeteor[i].direction.y * littleMeteor[i].speed * GetFrameTime();

		if (littleMeteor[i].pos.x >= GetScreenWidth())
		{
			littleMeteor[i].pos.x = 0;
		}
		else if (littleMeteor[i].pos.x <= 0)
		{
			littleMeteor[i].pos.x = GetScreenWidth();
		}
		if (littleMeteor[i].pos.y >= GetScreenHeight())
		{
			littleMeteor[i].pos.y = 0;
		}
		else if (littleMeteor[i].pos.y <= 0)
		{
			littleMeteor[i].pos.y = GetScreenHeight();
		}

	}

}