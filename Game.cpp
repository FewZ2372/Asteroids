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
	meteorDirection();
}

void drawGame()
{
	Vector2 rotation = { GetMouseX() - spaceShip.rec.x, GetMouseY() - spaceShip.rec.y };

	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawRectanglePro({ spaceShip.rec.x, spaceShip.rec.y, spaceShip.rec.width, spaceShip.rec.height },
		{ spaceShip.rec.width / 2, spaceShip.rec.height / 2 }, getRotation(rotation), BLUE);
	drawLasers();
	drawMeteors();
	EndDrawing();
}




