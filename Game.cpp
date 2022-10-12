#include "Game.h"
#include "MainMenu.h"
#include "SpaceShip.h"

void Update()
{
	checkPlay();
	checkCredits();
	checkQuit();
}

void RunGame(int i)
{
	scenesSwitch(i);
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


