#pragma once
#include "gameplay.h" 

#include "raylib.h" 
#include "raymath.h" 

namespace FewZ
{
	struct SpaceShip
	{
		Rectangle rec;
		Vector2 direction;
		float speed;
		float maxSpeed;
		int lives;
		int points;
		Texture2D textureMoving;
		Texture2D textureIdle;
	};
	extern SpaceShip spaceShip;
	extern Sound explosionSound;

	void setSpaceship();
	void spaceShipMovement();
	void accelerateSpaceShip(float axisX, float axisY, SpaceShip& spaceShip);
	void moveShip();
	
	float getRotation(Vector2 dir);

}
