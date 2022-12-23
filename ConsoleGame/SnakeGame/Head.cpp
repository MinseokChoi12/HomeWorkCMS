#include "Head.h"
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>
#include <conio.h>
#include "Body.h"

Head* Head::CurHead = nullptr;

Head* Head::GetCurHead()
{
	return CurHead;
}

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
				Body::CreatBody();
			}
		}
	}
}
