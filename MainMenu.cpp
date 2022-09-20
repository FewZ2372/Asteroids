#include "MainMenu.h"

void InitializeTexts()
{
	Texto[0].text = "PLAY";
	Texto[0].fontSize = 40;
	Texto[0].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[0].text.c_str(), 50) / 2 + 12;
	Texto[0].pos.y = 170;

	Texto[0].backgroundBttn.x = GetScreenWidth() / 2 - MeasureText(Texto[0].text.c_str(), 50) / 2;
	Texto[0].backgroundBttn.y = 163;
	Texto[0].backgroundBttn.width = MeasureText(Texto[0].text.c_str(), 50);
	Texto[0].backgroundBttn.height = 50;


	Texto[2].text = "CREDITS";
	Texto[2].fontSize = 40;
	Texto[2].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[2].text.c_str(), 50) / 2 + 22;
	Texto[2].pos.y = 310;

	Texto[2].backgroundBttn.x = GetScreenWidth() / 2 - MeasureText(Texto[2].text.c_str(), 50) / 2;
	Texto[2].backgroundBttn.y = 303;
	Texto[2].backgroundBttn.width = MeasureText(Texto[2].text.c_str(), 50);
	Texto[2].backgroundBttn.height = 50;


	Texto[3].text = "QUIT";
	Texto[3].fontSize = 40;
	Texto[3].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[3].text.c_str(), 50) / 2 + 13;
	Texto[3].pos.y = 380;

	Texto[3].backgroundBttn.x = GetScreenWidth() / 2 - MeasureText(Texto[3].text.c_str(), 50) / 2;
	Texto[3].backgroundBttn.y = 373;
	Texto[3].backgroundBttn.width = MeasureText(Texto[3].text.c_str(), 50);
	Texto[3].backgroundBttn.height = 50;

}

void DrawPlay()
{
	DrawRectangle(Texto[0].backgroundBttn.x, Texto[0].backgroundBttn.y, Texto[0].backgroundBttn.width, Texto[0].backgroundBttn.height, WHITE);
	DrawText(Texto[0].text.c_str(), Texto[0].pos.x, Texto[0].pos.y, Texto[0].fontSize, BLUE);

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[0].backgroundBttn))
	{
		menu = MenuScenes::Play;

	}
}

void DrawCredits()
{
	DrawRectangle(Texto[2].backgroundBttn.x, Texto[2].backgroundBttn.y, Texto[2].backgroundBttn.width, Texto[2].backgroundBttn.height, WHITE);
	DrawText(Texto[2].text.c_str(), Texto[2].pos.x, Texto[2].pos.y, Texto[2].fontSize, BLUE);

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[2].backgroundBttn))
	{
		menu = MenuScenes::Credits;

	}
}

void DrawQuit()
{
	DrawRectangle(Texto[3].backgroundBttn.x, Texto[3].backgroundBttn.y, Texto[3].backgroundBttn.width, Texto[3].backgroundBttn.height, WHITE);
	DrawText(Texto[3].text.c_str(), Texto[3].pos.x, Texto[3].pos.y, Texto[3].fontSize, RED);

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[3].backgroundBttn))
	{
		menu = MenuScenes::Quit;

	}
}

void drawMainMenu()
{
	switch (menu)
	{
	case MenuScenes::MainMenu:

		break;

	case MenuScenes::Play:


		break;

	case MenuScenes::PlayVsIA:


		break;

	case MenuScenes::Credits:


		break;

	case MenuScenes::Quit:


		break;

	case MenuScenes::Win:


		break;

	case MenuScenes::Lose:

		break;
	}

}