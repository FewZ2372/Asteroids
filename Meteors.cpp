#include "Meteors.h"

void setMeteors()
{
	for (int i = 0; i < 15; i++)
	{
		bigMeteor[i].pos.x = rand() % 1024;
		bigMeteor[i].pos.y = rand() % 768;

		if (bigMeteor[i].pos.x < GetScreenWidth() / 3 * 2 && bigMeteor[i].pos.x > GetScreenWidth() / 3 * 1)
		{
			bigMeteor[i].pos.x = rand() % 1024;
		}
		if (bigMeteor[i].pos.y < GetScreenHeight() / 6 * 2 && bigMeteor[i].pos.y > GetScreenHeight() / 6 * 4)
		{
			bigMeteor[i].pos.y = rand() % 768;
		}

		bigMeteor[i].speed = 80;
		bigMeteor[i].radio = 50;
		bigMeteor[i].life = 1;
		bigMeteor[i].isPrintable = true;

	}
}

void setMiddleMeteors()
{
	for (int i = 0; i < 30; i++)
	{
		middleMeteor[i].pos.x = bigMeteor[i].pos.x;
		middleMeteor[i].pos.y = bigMeteor[i].pos.y;
		middleMeteor[i].speed = 80;
		middleMeteor[i].radio = 25;
		middleMeteor[i].life = 1;
	}
}

void setLittleMeteors()
{
	for (int i = 0; i < 60; i++)
	{
		littleMeteor[i].pos.x = middleMeteor[i].pos.x;
		littleMeteor[i].pos.y = middleMeteor[i].pos.y;
		littleMeteor[i].speed = 80;
		littleMeteor[i].radio = 12;
		littleMeteor[i].life = 1;
	}
}

void drawMeteors()
{
	for (int i = 0; i < maxBigMeteors; i++)
	{
		if (bigMeteor[i].isPrintable)
		{
			DrawTexturePro(meteorTexture, { bigMeteor[i].pos.x, bigMeteor[i].pos.y, 100, 100 }, );
			DrawCircle(bigMeteor[i].pos.x, bigMeteor[i].pos.y, bigMeteor[i].radio, GREEN);
		}
	}

	for (int i = 0; i < maxMidMeteors; i++)
	{
		if (middleMeteor[i].isPrintable)
		{
			DrawCircle(middleMeteor[i].pos.x, middleMeteor[i].pos.y, middleMeteor[i].radio, GREEN);
		}
	}

	for (int i = 0; i < maxLittleMeteors; i++)
	{
		if (littleMeteor[i].isPrintable)
		{
			DrawCircle(littleMeteor[i].pos.x, littleMeteor[i].pos.y, littleMeteor[i].radio, GREEN);
		}
	}
}

void meteorDirection()
{
	for (size_t i = 0; i < maxBigMeteors; i++)
	{
		Vector2 newDirection;

		newDirection.x = static_cast<float>(rand() % 20);
		newDirection.y = static_cast<float>(rand() % 20);

		int aux = rand() % 2 + 1;

		if (aux == 2)
		{
			newDirection.x *= -1;
		}

		aux = rand() % 2 + 1;

		if (aux == 1)
		{
			newDirection.y *= -1;
		}

		newDirection = Vector2Normalize(newDirection);

		bigMeteor[i].direction = newDirection;
		bigMeteor[i].direction = newDirection;

		middleMeteor[i].direction = newDirection;
		middleMeteor[i].direction = newDirection;

		littleMeteor[i].direction = newDirection;
		littleMeteor[i].direction = newDirection;
	}
}

void moveBigMeteor()
{
	for (int i = 0; i < maxBigMeteors; i++)
	{
		bigMeteor[i].pos.x += bigMeteor[i].direction.x * bigMeteor[i].speed * GetFrameTime();
		bigMeteor[i].pos.y += bigMeteor[i].direction.y * bigMeteor[i].speed * GetFrameTime();

		if (bigMeteor[i].pos.x - bigMeteor[i].radio >= GetScreenWidth())
		{
			bigMeteor[i].pos.x = 0 - bigMeteor[i].radio;
		}
		else if (bigMeteor[i].pos.x + bigMeteor[i].radio <= 0)
		{
			bigMeteor[i].pos.x = GetScreenWidth() + bigMeteor[i].radio;
		}

		if (bigMeteor[i].pos.y - bigMeteor[i].radio >= GetScreenHeight())
		{
			bigMeteor[i].pos.y = 0 - bigMeteor[i].radio;
		}
		else if (bigMeteor[i].pos.y + bigMeteor[i].radio <= 0)
		{
			bigMeteor[i].pos.y = GetScreenHeight() + bigMeteor[i].radio;
		}
	}
}

void moveMidMeteor()
{
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
}

void moveLittleMeteor()
{
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

void checkCollisionsBigMeteor()
{
	for (int i = 0; i < maxBigMeteors; i++)
	{
		for (int j = 0; j < maxBullets; j++)
		{
			if (CheckCollisionCircles(bigMeteor[i].pos, bigMeteor[i].radio, lasers[j].pos, lasers[j].radius) && bigMeteor[i].isPrintable)
			{
				bigMeteor[i].isPrintable = false;

				lasers[j].isLoaded = true;

				middleMeteor[i].isPrintable = true;
				middleMeteor[i + 1].isPrintable = true;

				middleMeteor[i].pos.x = bigMeteor[i].pos.x;
				middleMeteor[i + 1].pos.x = bigMeteor[i].pos.x;

				middleMeteor[i].pos.y = bigMeteor[i].pos.y;
				middleMeteor[i + 1].pos.y = bigMeteor[i].pos.y;

				spaceShip.points++;
				
				moveMidMeteor();

			}
		}
		if (CheckCollisionCircleRec(bigMeteor[i].pos, bigMeteor[i].radio,spaceShip.rec) && bigMeteor[i].isPrintable)
		{
			bigMeteor[i].isPrintable = false;
			
			middleMeteor[i].isPrintable = true;
			middleMeteor[i + maxMidMeteors].isPrintable = true;

			middleMeteor[i].pos.x = bigMeteor[i].pos.x;
			middleMeteor[i + maxMidMeteors].pos.x = bigMeteor[i].pos.x;

			middleMeteor[i].pos.y = bigMeteor[i].pos.y;
			middleMeteor[i + maxMidMeteors].pos.y = bigMeteor[i].pos.y;

			spaceShip.lives--;

			moveMidMeteor();
		}
	}

}

void checkCollisionsMiddleMeteor()
{
	for (int i = 0; i < maxMidMeteors; i++)
	{
		for (int j = 0; j < maxBullets; j++)
		{
			if (CheckCollisionCircles(middleMeteor[i].pos, middleMeteor[i].radio, lasers[j].pos, lasers[j].radius) && middleMeteor[i].isPrintable)
			{
				middleMeteor[i].isPrintable = false;
				lasers[j].isLoaded = true;

				littleMeteor[i].pos.x = middleMeteor[i].pos.x;
				littleMeteor[i].pos.y = middleMeteor[i].pos.y;

				littleMeteor[i + maxLittleMeteors].pos.x = middleMeteor[i].pos.x;
				littleMeteor[i + maxLittleMeteors].pos.y = middleMeteor[i].pos.y;

				littleMeteor[i].isPrintable = true;
				littleMeteor[i + maxLittleMeteors].isPrintable = true;

				spaceShip.points++;

				moveMidMeteor();

			}
		}

		if (CheckCollisionCircleRec(middleMeteor[i].pos, middleMeteor[i].radio, spaceShip.rec) && middleMeteor[i].isPrintable)
		{
			middleMeteor[i].isPrintable = false;

			littleMeteor[i].pos.x = middleMeteor[i].pos.x;
			littleMeteor[i].pos.y = middleMeteor[i].pos.y;

			littleMeteor[i + maxLittleMeteors].pos.x = middleMeteor[i].pos.x;
			littleMeteor[i + maxLittleMeteors].pos.y = middleMeteor[i].pos.y;

			littleMeteor[i].isPrintable = true;
			littleMeteor[i + maxLittleMeteors].isPrintable = true;

			spaceShip.lives--;

			moveMidMeteor();
		}
	}

}