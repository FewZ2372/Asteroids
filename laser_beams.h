#pragma once
#include "game.h" 
#include "space_ship.h" 

#include "raylib.h" 

namespace FewZ
{
	struct LaserBeams
	{
		Vector2 direction;
		Vector2 pos;
		bool isLoaded;
		float speed;
		float radius;
		float lifeSpan;
	};

	const int maxBullets = 10;

	extern LaserBeams lasers[maxBullets];
	extern Sound laserSound;

	void loadLaserSound();
	void setLaserBeams();
	void laserBeamMovement();
	void moveLaserBeam(int i);
	void drawLasers();

}
