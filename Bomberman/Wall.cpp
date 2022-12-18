#include "Wall.h"
#include <conio.h>
#include <Windows.h>
#include "ConsoleGameScreen.h"

GameEngineArray<GameEngineArray<Wall>> Wall::WallMap;

void Wall::WallMapInit(int4 _Size)
{
	WallMap.ReSize(_Size.Y);

	for (int y = 0; y < WallMap.GetCount(); y++)
	{
		WallMap[y].ReSize(_Size.X);
		for (int x = 0; x < WallMap[y].GetCount(); x++)
		{
			WallMap[y][x].SetPos(int4{ x, y });

			WallMap[y][x].Off();
			if (y % 2 == 0)
				continue;
			if (x % 2 == 0)
				continue;

			WallMap[y][x].On();
		}
	}
}

void Wall::WallUpdata()
{
	for (int y = 0; y < WallMap.GetCount(); y++)
	{
		for (int x = 0; x < WallMap[y].GetCount(); x++)
		{
			if (false == WallMap[y][x].GetIsUpdate())
				continue;

			WallMap[y][x].Updata();
		}
	}
}

bool Wall::GetIsWall(int4 _Size)
{
	return WallMap[_Size.Y][_Size.X].GetIsUpdate();
}

Wall::Wall()
{	
	SetRenderChar(L'бр');
}

Wall::~Wall()
{
}

void Wall::Updata()
{
	Render();
}
