#include "Boom.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include "Wall.h"
#include <Windows.h>

GameEngineArray<GameEngineArray<Boom*>> Boom::BoomMap;

void Boom::BoomMapInit(int4 _Size)
{
	BoomMap.ReSize(_Size.Y);

	for (size_t y = 0; y < BoomMap.GetCount(); y++)
	{
		BoomMap[y].ReSize(_Size.X);
		for (size_t x = 0; x < BoomMap[y].GetCount(); x++)
		{
			BoomMap[y][x] = nullptr;
		}
	}
}

void Boom::MapClear()
{
	for (size_t y = 0; y < BoomMap.GetCount(); y++)
	{
		for (size_t x = 0; x < BoomMap[y].GetCount(); x++)
			BoomMap[y][x] = nullptr;
	}
}

Boom* Boom::GetBoom(int4 _Size)
{
	return BoomMap[_Size.Y][_Size.X];
}


Boom::Boom()
{
	SetRenderChar(L'¡Ý');
}

Boom::~Boom()
{
}

void Boom::Update()
{
	if (0 > Time)
	{
		return;
	}

	bool LeftWall = false;
	bool RightWall = false;
	bool UpWall = false;
	bool DownWall = false;

	if (Range > --Time)
	{
		for (int t = Range - Time; t > 0; t--)
		{
			for (size_t i = 0; i < 4; i++)
			{
				int4 unitPos[4] = { {0,-1}, {1,0}, {0,1}, {-1,0} };
				int4 Pos = GetPos() + unitPos[i] * (t - 1);
				if (ConsoleGameScreen::GetMainScreen()->IsOver(Pos) != true)
					ConsoleGameScreen::GetMainScreen()->SetPixelChar(Pos, L'¡Ú');
			}
		}			
	}	

	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
}
