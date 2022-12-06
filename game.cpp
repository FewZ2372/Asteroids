#include "game.h"

namespace FewZ
{
	Music music;
	bool isActive;

	void loadGameMusic()
	{
		music = LoadMusicStream("res/Song.wav");
	}

	void InitLoop()
	{
		while (isActive)
		{
			InitMusic();
			InitMenu();
		}
	}

	void InitMenu()
	{
		scenesSwitch();
	}

	void InitMusic()
	{
		PlayMusicStream(music);
		UpdateMusicStream(music);
	}

	void InitGame()
	{
		const int screenWidth = 1024;
		const int screenHeight = 768;

		srand(time(NULL));


		InitWindow(screenWidth, screenHeight, "Asteroids");
		InitAudioDevice();

		SetExitKey(NULL);

		isActive = true;
		loadGameMusic();
		loadDeathSound();
		loadSpaceShipTextures();
		loadLaserSound();
		loadMeteorSound();
		loadMeteorTexture();

		InitLoop();

		CloseAudioDevice();

		CloseWindow();
	}

	void unload()
	{
		UnloadTexture(meteorTexture);
		UnloadTexture(spaceShip.textureIdle);
		UnloadTexture(spaceShip.textureMoving);

		UnloadSound(impactMeteorSound);
		UnloadSound(laserSound);
		UnloadSound(explosionSound);

		UnloadMusicStream(music);
	}


}
