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

Texture meteorTexture;
Sound impactMeteorSound;
Sound laserSound;
Sound explosionSound;

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

	meteorTexture = LoadTexture("res/Meteor.png");
	impactMeteorSound = LoadSound("res/Impact.wav");
	laserSound = LoadSound("res/LaserBeam.wav");
	explosionSound = LoadSound("res/Explosion.wav");
	spaceShip.textureIdle = LoadTexture("res/SpaceShipIdle.png");
	spaceShip.textureMoving = LoadTexture("res/SpaceShipMoving.png");
	//--------------------------------------------------------------------------------------
	while (isActive)
	{
		RunGame();
	}

	CloseWindow();

	return 0;
}

