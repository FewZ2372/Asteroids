#pragma once
#include "game.h" 
#include "space_ship.h" 

#include "raylib.h" 

struct LaserBeams
{
	Vector2 direction;
	Vector2 pos;
	bool isLoaded;
	float speed;
	float radius;
	float lifeSpan;
};

const int maxBullets = 10;

extern LaserBeams lasers[maxBullets];

void moveLaserBeam(int i);
void laserBeamMovement();
void setLaserBeams();
void drawLasers();
