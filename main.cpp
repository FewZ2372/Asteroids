#include "game.h"
#include "main_menu.h"
#include "space_ship.h"
#include "laser_beams.h"
#include "meteors.h"

#include <iostream>
#include <ctime>

#include "raylib.h"


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

