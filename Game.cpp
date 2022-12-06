#include "Game.h"

void RunGame()
{
	float timePlayed = 0.0f;

	timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);

	if (timePlayed > 118.0f) timePlayed = 1.0f;

	UpdateMusicStream(music);
	scenesSwitch();
}

float getVectorMagnitude(Vector2 vec)
{
	return sqrtf(powf(vec.x, 2) + powf(vec.y, 2));
}

Vector2 normalizeVector(Vector2 vec)
{
	float mag = getVectorMagnitude(vec);

	return { vec.x / mag, vec.y / mag };
}

void updateGame()
{
	spaceShipMovement();
	laserBeamMovement();
	checkCollisionsBigMeteor();
	checkCollisionsMiddleMeteor();
	checkCollisionsLittleMeteor();


	moveBigMeteor();
	moveMidMeteor();
	moveLittleMeteor();

	if (spaceShip.points == 0)
	{
		menu = MenuScenes::Win;
	}

	if (spaceShip.lives <= 0)
	{
		PlaySound(explosionSound);
		menu = MenuScenes::Lose;
	}
}

void drawGame()
{
	Vector2 rotation = { GetMouseX() - spaceShip.rec.x, GetMouseY() - spaceShip.rec.y };

	BeginDrawing();
	ClearBackground(BLACK);


	drawLasers();
	DrawTexturePro(spaceShip.textureIdle, { -10 , 0, 200, 200 }, { spaceShip.rec.x, spaceShip.rec.y, 200, 200 }, { 85, 85 }, getRotation(rotation) - 90, WHITE);
	drawMeteors();
	DrawText(TextFormat("METEORS LEFT: " "%i", spaceShip.points), 5, 20, 20, WHITE);//POINTS DRAWING
	DrawText(TextFormat("LIVES: " "%i", spaceShip.lives), 5, 2, 20, WHITE);//LIVES DRAWING

	EndDrawing();
}

void InitGame()
{
	const int screenWidth = 1024;
	const int screenHeight = 768;

	srand(time(NULL));

	isActive = true;

	InitWindow(screenWidth, screenHeight, "Asteroids");

	SetExitKey(NULL);
	InitAudioDevice();

	music = LoadMusicStream("res/Song.wav");
	impactMeteorSound = LoadSound("res/Impact.wav");
	laserSound = LoadSound("res/LaserBeam.wav");
	explosionSound = LoadSound("res/Explosion.wav");
	meteorTexture = LoadTexture("res/Meteor.png");
	spaceShip.textureIdle = LoadTexture("res/SpaceShipIdle.png");
	spaceShip.textureMoving = LoadTexture("res/SpaceShipMoving.png");

	while (isActive)
	{
		RunGame();
	}

	UnloadTexture(meteorTexture);
	UnloadTexture(spaceShip.textureIdle);
	UnloadTexture(spaceShip.textureMoving);

	UnloadSound(impactMeteorSound);
	UnloadSound(laserSound);
	UnloadSound(explosionSound);

	UnloadMusicStream(music);

	CloseAudioDevice();

	CloseWindow();
}



