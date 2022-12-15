#include <iostream>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include "GameEngineDebug.h"
#include <conio.h>
#include "Map.h"

ConsoleGameScreen Screen;
Player MainPlayer;
Map MainMap;

int main()
{
	LeckCheck();

	int4 MapSize = { 15, 10 };

	Screen.ScreenInit(MapSize, L'　');


	while (true)
	{
		system("cls");
		Screen.ScreenClear();

		MainMap.CreateWall(MapSize);

		bool End = MainPlayer.Update();

		Screen.ScreenRender();
		Sleep(100);

		if (End == false)
		{
			MainMap.DestroyWall(MapSize);
			printf_s("게임을 종료했습니다.");
			break;
		}
		MainMap.DestroyWall(MapSize);
	}
}