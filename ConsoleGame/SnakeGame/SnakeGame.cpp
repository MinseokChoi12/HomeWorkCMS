#include <iostream>
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>
#include <conio.h>

#include "Head.h"
#include "Body.h"

ConsoleGameScreen Screen;
int4 ScreenSize = { 5, 5 };

int main()
{
	LeckCheck();

	Part* StartPart = new Head();

	Screen.ScreenInit(ScreenSize, L'бр');

	srand(time(nullptr));
	int Body_X = rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X;
	int Body_Y = rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y;

	int4 BodyPos = { Body_X, Body_Y };

	Body::CreatBody(BodyPos);

	while (true)
	{
		GameEngineInput::ConsoleInputCheck();
		if (true == GameEngineInput::GetIsInput()
			&& ('q' == GameEngineInput::GetKey()
				|| 'Q' == GameEngineInput::GetKey()))
		{
			break;
		}

		system("cls");
		Screen.ScreenClear();

		Body::GetCurBody()->Update();

		StartPart->Update();
		StartPart->RecursionBackRender();

		Body::GetCurBody()->Render();

		Screen.ScreenRender();
		Sleep(100);

		if (Head::GetGameOver())
			break;
	}

	Part* LastPart = StartPart->GetLastPart();
	Part::DestroyPart(LastPart, StartPart);

	if (nullptr != StartPart)
	{
		delete StartPart;
		StartPart = nullptr;
	}
}