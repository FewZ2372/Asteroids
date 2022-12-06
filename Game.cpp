#include "Game.h"

void RunGame()
{
	scenesSwitch();
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

	//if (spaceShip.points > 15)
	//{
	//	setMeteors();
	//	setMiddleMeteors();
	//	setLittleMeteors();
	//}

	if (spaceShip.lives <= 0)
	{
		PlaySound(explosionSound);
		menu = MenuScenes::MainMenu;
	}
}

void drawGame()
{
	Vector2 rotation = { GetMouseX() - spaceShip.rec.x, GetMouseY() - spaceShip.rec.y };

	BeginDrawing();
	ClearBackground(BLACK);


	DrawTexturePro(spaceShip.textureIdle, { -10 , 0, 200, 200 }, { spaceShip.rec.x, spaceShip.rec.y, 200, 200 }, { 85, 85 }, getRotation(rotation) - 90, WHITE);
	drawMeteors();
	drawLasers();
	DrawText(TextFormat("POINTS: " "%i", spaceShip.points), 5, 20, 20, WHITE);//POINTS DRAWING
	DrawText(TextFormat("LIVES: " "%i", spaceShip.lives), 5, 2, 20, WHITE);//LIVES DRAWING

	EndDrawing();
}




