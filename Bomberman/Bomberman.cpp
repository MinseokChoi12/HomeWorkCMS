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

int4 MapSize = { 15, 11 };

int main()
{
	LeckCheck();

	Screen.ScreenInit(MapSize, L'■');

	Boom::BoomMapInit(MapSize);
	Wall::WallMapInit(MapSize);
	Monster::AllMonsterInit(L'§');

	Monster::CreateMonster(int4{ 0, 2 }, int4::LEFT);
	Monster::CreateMonster(int4{ 0, 3 }, int4::UP);
	Monster::CreateMonster(int4{ 0, 4 }, int4::RIGHT);

	while (true)
	{
		system("cls");
		Screen.ScreenClear();

		Wall::WallUpdata();
		Monster::AllMonsterUpdate();

		bool End = MainPlayer.Update();

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