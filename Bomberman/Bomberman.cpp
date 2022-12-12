#include <iostream>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include "GameEngineDebug.h"
#include <conio.h>

ConsoleGameScreen Screen;
Player MainPlayer;

int main()
{
	LeckCheck();

	Screen.ScreenInit({ 15, 10 }, L'■');

	while (true)
	{
		system("cls");
		Screen.ScreenClear();

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