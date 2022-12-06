#pragma once
#include "laser_beams.h"
#include "space_ship.h"

#include "raylib.h" 

#include <String>

using namespace std;

namespace FewZ
{
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

	void initializeTexts();
	void drawPlay();
	void checkPlay();
	void drawCredits();
	void checkCredits();
	void drawQuit();
	void checkQuit();
	void drawButtons();
	void updateMenu();
	void scenesSwitch();
}