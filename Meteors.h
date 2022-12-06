#pragma once
#include "raylib.h" 
#include "Game.h" 
#include "LaserBeams.h" 
#include "SpaceShip.h" 

#include "ctime" 

struct Meteors
{
	Rectangle pos;
	Vector2 direction;
	float speed;
	float rotation;
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
extern Texture2D meteorTexture;

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
void checkCollisionsLittleMeteor();

