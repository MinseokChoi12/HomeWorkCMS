#include <iostream>
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "GameEngineDebug.h"
#include "Player.h"
#include "Wall.h"
#include "Boom.h"
#include "Monster.h"

ConsoleGameScreen Screen;
Player MainPlayer;
Monster Monster1;
Monster Monster2;

int4 MapSize = { 15, 11 };

int main()
{
	LeckCheck();

	Screen.ScreenInit(MapSize, L'　');

	Boom::BoomMapInit(MapSize);
	Wall::WallMapInit(MapSize);

	while (true)
	{
		system("cls");
		Screen.ScreenClear();

		Wall::WallUpdata();

		bool End = MainPlayer.Update();
		Monster1.Update(MapSize, 1);
		Monster2.Update(MapSize, 2);

		Screen.ScreenRender();
		Sleep(100);

		Boom::MapClear();

		if (End == false)
		{
			printf_s("게임을 종료했습니다.");
			break;
		}
	}
}