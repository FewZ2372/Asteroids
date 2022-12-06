#pragma once
#include "raylib.h"
#include "MainMenu.h"
#include "SpaceShip.h"
#include "LaserBeams.h"
#include "Meteors.h" 

extern Sound impactMeteorSound;
extern Sound laserSound;
extern Sound explosionSound;
extern bool isActive;
void RunGame();
void drawGame();
void updateGame();
float getVectorMagnitude(Vector2 vec);
Vector2 normalizeVector(Vector2 vec);
