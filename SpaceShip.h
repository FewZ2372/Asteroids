#pragma once
#include "raylib.h" 

struct SpaceShip
{
	Rectangle rec{};
	float speed;
	float direction;

};
extern SpaceShip spaceShip;

void setSpaceship();