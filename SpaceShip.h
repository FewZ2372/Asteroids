#pragma once
#include "raylib.h" 
#include "raymath.h" 
#include "Game.h" 

struct SpaceShip
{
	Rectangle rec;
	Vector2 direction;
	float speed;
	float maxSpeed;
	int lives;
};
extern SpaceShip spaceShip;

float getRotation(Vector2 dir);
void moveShip();
void setSpaceship();
void spaceShipMovement();
void accelerateSpaceShip(float axisX, float axisY, SpaceShip& spaceShip);
