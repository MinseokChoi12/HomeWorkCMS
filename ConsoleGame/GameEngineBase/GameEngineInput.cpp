#include "GameEngineInput.h"
#include <conio.h>

bool GameEngineInput::IsInput;
int GameEngineInput::CurKey;

void GameEngineInput::ConsoleInputCheck()
{
	IsInput = false;

	if (0 == _kbhit())
		return;

	IsInput = true;
	CurKey = _getch();
}

GameEngineInput::GameEngineInput()
{
}

GameEngineInput::~GameEngineInput()
{
}
