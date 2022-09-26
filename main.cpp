#include "raylib.h"
#include "Game.h"
#include "MainMenu.h"
#include "SpaceShip.h"

MenuScenes menu;	
Buttons Texto[3];
SpaceShip spaceShip;

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;

	
	InitWindow(screenWidth, screenHeight, "Meteoroids");
	initializeTexts();
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

