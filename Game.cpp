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
	checkCollisionsBigMeteor();
	checkCollisionsMiddleMeteor();

	spaceShipMovement();
	laserBeamMovement();
	moveBigMeteor();
	moveMidMeteor();
	moveLittleMeteor();

	if (spaceShip.lives == 0)
	{
		menu = MenuScenes::MainMenu;
	}
}

void drawGame()
{
	Vector2 rotation = { GetMouseX() - spaceShip.rec.x, GetMouseY() - spaceShip.rec.y };

	BeginDrawing();
	ClearBackground(BLACK);

	DrawRectanglePro({ spaceShip.rec.x, spaceShip.rec.y, spaceShip.rec.width, spaceShip.rec.height },
		{ spaceShip.rec.width / 2, spaceShip.rec.height / 2 }, getRotation(rotation), BLUE);
	drawLasers();
	drawMeteors();
	DrawText(TextFormat("POINTS: " "%i", spaceShip.points), 5, 20, 20, WHITE);//POINTS DRAWING
	DrawText(TextFormat("LIVES: " "%i", spaceShip.lives), 5, 2, 20, WHITE);//LIVES DRAWING

	EndDrawing();
}




