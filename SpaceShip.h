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
	int bullets;
	int points;
	Texture2D textureMoving;
	Texture2D textureIdle;
};
extern SpaceShip spaceShip;

float getRotation(Vector2 dir);
void moveShip();
void setSpaceship();
void spaceShipMovement();
void accelerateSpaceShip(float axisX, float axisY, SpaceShip& spaceShip);
