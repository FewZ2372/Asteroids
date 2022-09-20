#pragma once
#include "raylib.h" 
#include <String>

using namespace std;

enum class MenuScenes
{
	MainMenu,
	Play,
	Credits,
	Quit,
	Win,
	Lose
};
MenuScenes menu;

struct Buttons
{
	string text{};
	Vector2 pos{};
	int fontSize{};

	Rectangle backgroundBttn{};
};
Buttons Texto[4];

void drawMainMenu();