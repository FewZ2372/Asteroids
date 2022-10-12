#pragma once
#include "raylib.h" 
#include "Game.h" 

struct LaserBeams
{
	Rectangle rec;
	Vector2 direction;
	bool isLoaded;
	float speed;
	float radius;
};
const int maxBullets = 10;

extern LaserBeams lasers[maxBullets];

void laserBeamMovement();
void moveLaserBeam(int i);
void setLaserBeams(int i);
