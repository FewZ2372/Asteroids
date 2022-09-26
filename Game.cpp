#include "Game.h"
#include "MainMenu.h"
#include "SpaceShip.h"

void Update()
{
	spaceShip.rec.x = GetMouseX();
	spaceShip.rec.y = GetMouseY();
	spaceShip.rec.width = 40;
	spaceShip.rec.height = 80;

	checkPlay();
	checkCredits();
	checkQuit();
}

void RunGame()
{
	scenesSwitch();
}


