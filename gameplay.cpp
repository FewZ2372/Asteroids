#include "gameplay.h"

namespace FewZ
{

	void updateGame()
	{
		spaceShipMovement();
		laserBeamMovement();
		checkCollisionsBigMeteor();
		checkCollisionsMiddleMeteor();
		checkCollisionsLittleMeteor();

		moveBigMeteor();
		moveMidMeteor();
		moveLittleMeteor();

		winCondition();
		loseCondition();
	}

	void drawGame()
	{
		spaceShip.textureIdle = LoadTexture("res/SpaceShipIdle.png");
		spaceShip.textureMoving = LoadTexture("res/SpaceShipMoving.png");

		Vector2 rotation = { GetMouseX() - spaceShip.rec.x, GetMouseY() - spaceShip.rec.y };

		BeginDrawing();
		ClearBackground(BLACK);

		drawLasers();
		DrawTexturePro(spaceShip.textureIdle, { -10 , 0, 200, 200 }, { spaceShip.rec.x, spaceShip.rec.y, 200, 200 }, { 85, 85 }, getRotation(rotation) - 90, WHITE);
		drawMeteors();
		DrawText(TextFormat("METEORS LEFT: " "%i", spaceShip.points), 5, 20, 20, WHITE);//POINTS DRAWING
		DrawText(TextFormat("LIVES: " "%i", spaceShip.lives), 5, 2, 20, WHITE);//LIVES DRAWING

		EndDrawing();
	}

	float getVectorMagnitude(Vector2 vec)
	{
		return sqrtf(powf(vec.x, 2) + powf(vec.y, 2));
	}

	Vector2 normalizeVector(Vector2 vec)
	{
		float mag = getVectorMagnitude(vec);

		return { vec.x / mag, vec.y / mag };
	}

	void winCondition()
	{
		if (spaceShip.points == 0)
		{
			menu = MenuScenes::Win;
		}
	}

	void loseCondition()
	{
		explosionSound = LoadSound("res/Explosion.wav");

		if (spaceShip.lives <= 0)
		{
			PlaySound(explosionSound);
			menu = MenuScenes::Lose;
		}
	}
}

