#pragma once
#include "raylib.h" 
#include "raymath.h" 

struct SpaceShip
{
	Rectangle rec{};
	Vector2 direction;
	float speed;
	float maxSpeed;
	int lives;
};
extern SpaceShip spaceShip;

float getVectorMagnitude(Vector2 vec);
float getRotation(Vector2 dir);
void moveShip();
void setSpaceship();
void spaceShipMovement();
void accelerateSpaceShip(float axisX, float axisY, SpaceShip& spaceShip);
Vector2 normalizeVector(Vector2 vec);
