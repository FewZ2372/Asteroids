#pragma once
#include "raylib.h" 
#include "raymath.h" 

struct SpaceShip
{
	Rectangle rec{};
	float speed;
	float directionX;
	float direcitonY;
	float maxSpeed;
	int lives;
};
extern SpaceShip spaceShip;

void setSpaceship();