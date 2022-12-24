#include "Head.h"
#include <iostream>
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>
#include <conio.h>
#include "Body.h"

Head* Head::CurHead = nullptr;
bool Head::GameOver = false;

Head::Head()
	: Part(L'¡ß')
{
	CurHead = this;
}

Head::~Head()
{
}

void Head::Update()
{
	if (true == GameEngineInput::GetIsInput())
	{

	}

	if (true == GameEngineInput::GetIsInput())
	{
		int Input = GameEngineInput::GetKey();
		int4 NextPos = GetPos();

		switch (Input)
		{

		case 'a':
		case 'A':
		{
			NextPos += {-1, 0};
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
		break;
		case 'q':
		case 'Q':
			return;
		default:
			break;
		}
		}

		bool IsMove = true;

		if (true == ConsoleGameScreen::GetMainScreen()->IsOver(NextPos))
		{
			IsMove = false;
		}

		if (IsBody(this, NextPos))
		{
			int a = 0;
			GameOver = true;
		}

		if (true == IsMove)
		{
			Part* LastPart = GetLastPart();
			int4 PrevPos = LastPart->GetPos();

			LastPart->RecursionFrontMove();
			SetPos(NextPos);

			if (GetPos() == Body::GetCurBody()->GetPos())
			{
				Body::GetCurBody()->SetPos(PrevPos);
				Body::GetCurBody()->SetRenderChar(L'¡Ü');
				LastPart->SetBack(Body::GetCurBody());

				while (true)
				{
					srand(time(nullptr));
					int Body_X = rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X;
					int Body_Y = rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y;

					int4 BodyPos = { Body_X, Body_Y };
					int4 NewBodyPos = Body::EmptyPos(this, BodyPos);

					if (NewBodyPos != int4{ -1,-1 })
					{
						Body::CreatBody(NewBodyPos);
						break;
					}
				}
			}
		}
	}
}

bool Head::IsBody(Part* _Part, int4 _NextPos)
{
	Part* NextBody = _Part->GetBack();

	if (NextBody == nullptr)
		return false;
	else if (NextBody->GetPos() == _NextPos)
		return true;
	else
		IsBody(NextBody, _NextPos);
}
