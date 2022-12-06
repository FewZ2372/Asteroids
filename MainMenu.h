#pragma once
#include "raylib.h" 
#include "SpaceShip.h"
#include "LaserBeams.h"
#include <String>

using namespace std;

enum class MenuScenes
{
	MainMenu,
	Play,
	Credits,
	Win,
	Lose,
	Quit,

};
extern MenuScenes menu;

struct Buttons
{
	string text{};
	Vector2 pos{};
	int fontSize{};

	Rectangle backgroundBttn{};
};
extern Buttons Texto[3];

void scenesSwitch();
void initializeTexts();
void drawButtons();
void updateMenu();
void checkPlay();
void drawCredits();
void checkCredits();
void drawQuit();
void checkQuit();