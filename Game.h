#pragma once
#include "main_menu.h"
#include "space_ship.h"
#include "laser_beams.h"
#include "meteors.h" 

#include "raylib.h"

extern Sound impactMeteorSound;
extern Sound laserSound;
extern Sound explosionSound;
extern Music music;
extern bool isActive;
void RunGame();
void InitGame();
void drawGame();
void updateGame();
float getVectorMagnitude(Vector2 vec);
Vector2 normalizeVector(Vector2 vec);
