#pragma once
#include "raylib.h" 
#include "Game.h" 
#include "SpaceShip.h" 

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
