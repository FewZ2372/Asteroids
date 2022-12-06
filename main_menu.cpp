#include "main_menu.h"


namespace FewZ
{
	MenuScenes menu;
	Buttons Texto[3];

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

	void updateMenu()
	{
		checkPlay();
		checkCredits();
		checkQuit();
	}

	void scenesSwitch()
	{
		switch (menu)
		{
		case MenuScenes::MainMenu:

			initializeTexts();
			setSpaceship();
			setLaserBeams();
			setMeteors();
			setMiddleMeteors();
			setLittleMeteors();
			meteorDirection();
			updateMenu();
			drawButtons();

			break;

		case MenuScenes::Play:

			updateGame();
			drawGame();

			break;

		case MenuScenes::Credits:

			BeginDrawing();
			ClearBackground(BLACK);
			DrawText("Meteor textures by Kenney: https://kenney.nl/assets/space-shooter-extension", 3, 50, 15, WHITE);
			DrawText("Shooting sound effect by GamingSoundEffects: https://www.youtube.com/watch?v=FuvmTL1nPDs&ab_channel=GamingSoundEffects", 3, 150, 15, WHITE);
			DrawText("SpaceShip explosion sound effect by AudioForLife: https://www.youtube.com/watch?v=Y2A43FW0fb4&ab_channel=AudioForLife", 3, 250, 15, WHITE);
			DrawText("Impacting meteors sound effect by AudioForLife: https://www.youtube.com/watch?v=Y2A43FW0fb4&ab_channel=AudioForLife", 3, 350, 15, WHITE);
			DrawText("Ambience music by Charlie Axl Tebbutt: https://www.youtube.com/watch?v=9aKIkh4gfqs&ab_channel=CharlieAxlTebbutt", 3, 450, 15, WHITE);
			DrawText("SpaceShip textures made by Me.", 3, 550, 15, WHITE);
			DrawText("Press 'B' to go back to menu.", 30, 650, 20, RED);
			EndDrawing();

			if (IsKeyDown(KEY_B))
			{
				menu = MenuScenes::MainMenu;
			}

			break;

		case MenuScenes::Win:

			BeginDrawing();
			ClearBackground(BLACK);

			DrawText("YOU WON", 300, GetScreenHeight() / 2, 40, WHITE);
			DrawText("Press 'M' to go back to menu.", 30, 650, 20, RED);

			if (IsKeyDown(KEY_M))
			{
				menu = MenuScenes::MainMenu;
			}

			EndDrawing();

			break;

		case MenuScenes::Lose:

			BeginDrawing();
			ClearBackground(BLACK);

			DrawText("YOU LOST", 300, GetScreenHeight() / 2, 40, WHITE);
			DrawText("Press 'M' to go back to menu.", 30, 650, 20, RED);

			if (IsKeyDown(KEY_M))
			{
				menu = MenuScenes::MainMenu;
			}

			EndDrawing();

			break;

		case MenuScenes::Quit:

			isActive = false;

			break;
		}

		if (WindowShouldClose())
		{
			isActive = false;
		}
	}
}