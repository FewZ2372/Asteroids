#include "game.h"

namespace FewZ
{
	Music music;
	bool isActive;

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
		music = LoadMusicStream("res/Song.wav");
		PlayMusicStream(music);
		UpdateMusicStream(music);
	}


	void InitGame()
	{
		const int screenWidth = 1024;
		const int screenHeight = 768;

		srand(time(NULL));

		SetExitKey(NULL);

		InitAudioDevice();

		isActive = true;

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
