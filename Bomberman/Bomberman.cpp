#include <iostream>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include "GameEngineDebug.h"
#include <conio.h>
#include "Wall.h"

ConsoleGameScreen Screen;
Player MainPlayer;
Wall wall;

int main()
{
	LeckCheck();

	int4 MapSize = { 15, 10 };

	Screen.ScreenInit(MapSize, L'　');


	while (true)
	{
		system("cls");
		Screen.ScreenClear();

		wall.CreateWall(MapSize);

		bool End = MainPlayer.Update();

		Screen.ScreenRender();
		Sleep(100);

		if (End == false)
		{
			printf_s("게임을 종료했습니다.");
			break;
		}
	}
}