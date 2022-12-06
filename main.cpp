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

bool isActive;

int main(void)
{
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1024;
	const int screenHeight = 768;

	srand(time(NULL));

	isActive = true;

	InitWindow(screenWidth, screenHeight, "Asteroids");
	
	SetExitKey(NULL);
	InitAudioDevice();

	Texture2D meteorTexture = LoadTexture("res/Meteor.png");
	Sound impactMeteorSound = LoadSound("res/Impact.wav");
	Sound laserSound = LoadSound("res/LaserBeam.wav");
	Sound explosionSound = LoadSound("res/Explosion.wav");

	//--------------------------------------------------------------------------------------
	while (isActive)
	{
		RunGame();
	}

	CloseWindow();        

	return 0;
}

