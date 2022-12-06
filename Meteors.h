#pragma once
#include "raylib.h" 
#include "Game.h" 
#include <iostream>

struct Meteors
{
	Vector2 pos;
	Vector2 direction;
	float speed;
	int life;
	int radio;
};

const int maxBigMeteors = 15;
const int maxMidMeteors = 30;
const int maxLittleMeteors = 60;

extern Meteors bigMeteor[maxBigMeteors];
extern Meteors middleMeteor[maxMidMeteors];
extern Meteors littleMeteor[maxLittleMeteors];

void setBigMeteors();
void setMiddleMeteors();
void setLittleMeteors();
void drawMeteors();
void meteorDirection();
void moveMeteor();