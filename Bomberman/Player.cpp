#include "Player.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "GameEngineDebug.h"
#include "Boom.h"

Player::Player()
{
	ArrBoomObject = new Boom[1000]();

	SetRenderChar(L'＠');
}

Player::~Player()
{
	if (ArrBoomObject != nullptr)
	{
		delete[] ArrBoomObject;
		ArrBoomObject = nullptr;
	}
}

bool Player::Update()
{
	if (ArrBoomObject == nullptr)
	{
		MessageBoxAssert("폭탄이 만들어지지 않았습니다");
		return false;
	}

	for (size_t i = 0; i < BoomUseCount; i++)
	{
		ArrBoomObject[i].Update();
	}

	if (_kbhit() == 0)
	{
		ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());

		return true;
	}

	int Input = _getch();

	int4 NextPos = GetPos();

	switch (Input)
	{
	case 'a':
	case 'A':
	{
		NextPos += {-1, 0};
	}
	break;
	case 'd':
	case 'D':
	{
		NextPos += {1, 0 };
	}
	break;
	case 's':
	case 'S':
	{
		NextPos += { 0, 1 };
	}
	break;
	case 'w':
	case 'W':
	{
		NextPos += { 0, -1 };
	}
	break;
	case 'f':
	case 'F':
	{
		Boom& NewBoomObject = ArrBoomObject[BoomUseCount];
		NewBoomObject.SetPos(GetPos());
		++BoomUseCount;
	}
	break;
	case 'q':
	case 'Q':
		return false;
	default:
		break;
	}

	bool IsMove = true;

	if (true == ConsoleGameScreen::GetMainScreen()->IsOver(NextPos))
	{
		IsMove = false;
	}

	for (size_t i = 0; i < BoomUseCount; i++)
	{
		if ((ArrBoomObject[i].IsDeath() == false) && (ArrBoomObject[i].GetPos() == NextPos))
		{
			IsMove = false;
		}
	}

	if (IsMove == true)
	{
		SetPos(NextPos);
	}

	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());

	return true;
}
