#pragma once
#include "raylib.h" 
#include "Game.h" 
#include <iostream>

struct Meteors
{
	Rectangle rec;
	Vector2 direction;
	float speed;
	int life;
};
extern Meteors bigMeteor[15];
extern Meteors middleMeteor[30];
extern Meteors littleMeteor[60];

void setBigMeteors();
void setMiddleMeteors();
