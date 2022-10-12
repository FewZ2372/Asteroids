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
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1024;
	const int screenHeight = 768;

	srand(time(NULL));

	InitWindow(screenWidth, screenHeight, "Asteroids");
	initializeTexts();
	setSpaceship();

	for (int i = 0; i < maxBullets; i++)
	{
		setLaserBeams(i);
	}

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		Update();
		RunGame();
	}
	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}

