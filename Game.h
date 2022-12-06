#pragma once
#include "raylib.h"
#include "MainMenu.h"
#include "SpaceShip.h"
#include "LaserBeams.h"
#include "Meteors.h" 

void RunGame();
void drawGame();
void updateGame();
float getVectorMagnitude(Vector2 vec);
Vector2 normalizeVector(Vector2 vec);
