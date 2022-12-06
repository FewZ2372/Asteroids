#include "raylib.h"
#include "Game.h"
#include "MainMenu.h"
#include "SpaceShip.h"
#include "LaserBeams.h"
#include "Meteors.h"
#include <iostream>
#include <ctime>

MenuScenes menu;

Buttons Texto[3];

SpaceShip spaceShip;
LaserBeams lasers[maxBullets];

Meteors bigMeteor[15];
Meteors middleMeteor[30];
Meteors littleMeteor[60];

int main(void)
{
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1024;
	const int screenHeight = 768;

	srand(time(NULL));

	InitWindow(screenWidth, screenHeight, "Asteroids");

	//--------------------------------------------------------------------------------------
	while (!WindowShouldClose())
	{
		RunGame();
	}

	CloseWindow();        

	return 0;
}

