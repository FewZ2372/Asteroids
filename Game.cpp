#include "Game.h"
#include "MainMenu.h"
#include "SpaceShip.h"

void Update()
{
	checkPlay();
	checkCredits();
	checkQuit();
}

void RunGame()
{
	scenesSwitch();
}


