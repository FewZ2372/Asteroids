#pragma once
#include "raylib.h" 
#include "Game.h" 
#include "LaserBeams.h" 
#include "SpaceShip.h" 

#include "ctime" 

struct Meteors
{

	Vector2 pos;
	Vector2 direction;
	float speed;
	int life;
	int radio;
	bool isPrintable;
};

const int maxBigMeteors = 15;
const int maxMidMeteors = 30;
const int maxLittleMeteors = 60;

extern Meteors bigMeteor[maxBigMeteors];
extern Meteors middleMeteor[maxMidMeteors];
extern Meteors littleMeteor[maxLittleMeteors];

void setMeteors();
void setMiddleMeteors();
void setLittleMeteors();
void drawMeteors();
void meteorDirection();
void moveBigMeteor();
void moveMidMeteor();
void moveLittleMeteor();
void checkCollisionsBigMeteor();
void checkCollisionsMiddleMeteor();
