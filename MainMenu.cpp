#include "MainMenu.h"

void initializeTexts()
{
	Texto[0].text = "PLAY";
	Texto[0].fontSize = 40;
	Texto[0].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[0].text.c_str(), 50) / 2 + 12;
	Texto[0].pos.y = 170;

	Texto[0].backgroundBttn.x = GetScreenWidth() / 2 - MeasureText(Texto[0].text.c_str(), 50) / 2;
	Texto[0].backgroundBttn.y = 163;
	Texto[0].backgroundBttn.width = MeasureText(Texto[0].text.c_str(), 50);
	Texto[0].backgroundBttn.height = 50;


	Texto[1].text = "CREDITS";
	Texto[1].fontSize = 40;
	Texto[1].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[1].text.c_str(), 50) / 2 + 22;
	Texto[1].pos.y = 310;

	Texto[1].backgroundBttn.x = GetScreenWidth() / 2 - MeasureText(Texto[1].text.c_str(), 50) / 2;
	Texto[1].backgroundBttn.y = 303;
	Texto[1].backgroundBttn.width = MeasureText(Texto[1].text.c_str(), 50);
	Texto[1].backgroundBttn.height = 50;


	Texto[2].text = "QUIT";
	Texto[2].fontSize = 40;
	Texto[2].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[2].text.c_str(), 50) / 2 + 13;
	Texto[2].pos.y = 380;

	Texto[2].backgroundBttn.x = GetScreenWidth() / 2 - MeasureText(Texto[2].text.c_str(), 50) / 2;
	Texto[2].backgroundBttn.y = 373;
	Texto[2].backgroundBttn.width = MeasureText(Texto[2].text.c_str(), 50);
	Texto[2].backgroundBttn.height = 50;
}

void drawPlay()
{
	DrawRectangle(Texto[0].backgroundBttn.x, Texto[0].backgroundBttn.y, Texto[0].backgroundBttn.width, Texto[0].backgroundBttn.height, WHITE);
	DrawText(Texto[0].text.c_str(), Texto[0].pos.x, Texto[0].pos.y, Texto[0].fontSize, BLUE);
}

void checkPlay()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[0].backgroundBttn))
	{
		menu = MenuScenes::Play;
	}
}

void drawCredits()
{
	DrawRectangle(Texto[1].backgroundBttn.x, Texto[1].backgroundBttn.y, Texto[1].backgroundBttn.width, Texto[1].backgroundBttn.height, WHITE);
	DrawText(Texto[1].text.c_str(), Texto[1].pos.x, Texto[1].pos.y, Texto[1].fontSize, BLUE);
}

void checkCredits()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[1].backgroundBttn))
	{
		menu = MenuScenes::Credits;
	}
}

void drawQuit()
{
	DrawRectangle(Texto[2].backgroundBttn.x, Texto[2].backgroundBttn.y, Texto[2].backgroundBttn.width, Texto[2].backgroundBttn.height, WHITE);
	DrawText(Texto[2].text.c_str(), Texto[2].pos.x, Texto[2].pos.y, Texto[2].fontSize, RED);
}

void checkQuit()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[2].backgroundBttn))
	{
		menu = MenuScenes::Quit;
	}
}

void drawButtons()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	drawPlay();
	drawCredits();
	drawQuit();
	EndDrawing();
}

void play()
{
	Vector2 rotation = { GetMouseX() - spaceShip.rec.x, GetMouseY() - spaceShip.rec.y };

	updatePlay();
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawRectanglePro({ spaceShip.rec.x, spaceShip.rec.y, spaceShip.rec.width, spaceShip.rec.height },
		{ spaceShip.rec.width / 2, spaceShip.rec.height / 2 }, getRotation(rotation), BLUE);

	for (int i = 0; i < maxBullets; i++)
	{
		if (lasers[i].isLoaded == false)
		{
			DrawCircle(lasers[i].rec.x, lasers[i].rec.y, lasers[i].radius, RED);
		}
	}

	EndDrawing();
}

void updatePlay()
{
	spaceShipMovement();
	laserBeamMovement();
}

void scenesSwitch()
{
	switch (menu)
	{
	case MenuScenes::MainMenu:

		drawButtons();

		break;

	case MenuScenes::Play:

		play();

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