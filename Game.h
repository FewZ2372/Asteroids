#pragma once
#include "main_menu.h"
#include "space_ship.h"
#include "laser_beams.h"
#include "meteors.h" 

#include "raylib.h"

namespace FewZ
{
	extern Music music;
	extern bool isActive;

	void loadGameMusic();
	void InitLoop();
	void InitMenu();
	void InitGame();
	void InitMusic();
	void unload();

}
