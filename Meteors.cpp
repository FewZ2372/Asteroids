#include "Meteors.h"


void setBigMeteors()
{
	for (int i = 0; i < 15; i++)
	{
		bigMeteor[i].rec.x = rand() % 1024;
		bigMeteor[i].rec.y = rand() % 768;
		bigMeteor[i].rec.width = 70;
		bigMeteor[i].rec.height = 70;
		bigMeteor[i].speed = 45;
		bigMeteor[i].life = 2;
	}
}

void setMiddleMeteors()
{
	for (int i = 0; i < 30; i++)
	{
		middleMeteor[i].rec.x = rand() % 1024;
		middleMeteor[i].rec.y = rand() % 768;
		middleMeteor[i].rec.width = 35;
		middleMeteor[i].rec.height = 35;
		middleMeteor[i].speed = 45;
		middleMeteor[i].life = 1;
	}
}

void setLittleMeteors()
{
	for (int i = 0; i < 60; i++)
	{
		littleMeteor[i].rec.x = rand() % 1024;
		littleMeteor[i].rec.y = rand() % 768;
		littleMeteor[i].rec.width = 15;
		littleMeteor[i].rec.height = 15;
		littleMeteor[i].speed = 45;
		littleMeteor[i].life = 1;
	}
}