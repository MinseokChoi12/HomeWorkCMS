#include "Monster.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "GameEngineDebug.h"
#include "Boom.h"
#include "Wall.h"

Monster::Monster()
{
	SetRenderChar(L'¡×');
	SetPos(int4{ 6, 6 });
}

Monster::~Monster()
{
}

void Monster::Update(int4 _Size, int _num)
{
	if (_num == 1)
	{
		if (dir == 1.0f && GetPos().X >= _Size.X - 1)
		{
			dir = -1.0f;
			Time = 0;
		}
		else if (dir == -1 && GetPos().X <= 0)
		{
			dir = 1.0f;
			Time = 0;
		}

		Time += dir * 0.1f;

		int4 Pos = GetPos();
		Pos.X += (int)Time;
		SetPos(Pos);
	}
	
	if (_num == 2)
	{
		if (dir == 1.0f && GetPos().Y >= _Size.Y - 1)
		{
			dir = -1.0f;
			Time = 0;
		}
		else if (dir == -1 && GetPos().Y <= 0)
		{
			dir = 1.0f;
			Time = 0;
		}

		Time += dir * 0.1f;

		int4 Pos = GetPos();
		Pos.Y += (int)Time;
		SetPos(Pos);
	}
	
	
	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
}
