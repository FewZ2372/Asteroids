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
Music music;

int main(void)
{
	InitGame();
}

