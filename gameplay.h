#pragma once
#include "main_menu.h"
#include "space_ship.h"
#include "laser_beams.h"
#include "meteors.h"

#include "raylib.h"

namespace FewZ
{
	void updateGame();
	void drawGame();
	float getVectorMagnitude(Vector2 vec);
	Vector2 normalizeVector(Vector2 vec);
	void winCondition();
	void loseCondition();
}