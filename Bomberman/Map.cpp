#include "Map.h"
#include <conio.h>
#include <Windows.h>
#include "ConsoleGameScreen.h"
#include "Wall.h"
#include <iostream>


Wall*** Map::WallArr = nullptr;


Map::Map()
{
	SetRenderChar(L'бс');
}

Map::~Map()
{
}

void Map::CreateWall(const int4& _Size)
{
	WallArr = new Wall** [10]();
	for (int y = 0; y < _Size.Y; y++)
	{
		WallArr[y] = new Wall* [15]();
		for (int x = 0; x < _Size.X; x++)
		{
			if (y % 2 == 1 && x % 2 == 1)
			{
				WallArr[y][x] = new Wall;
				Wall* NewWall = WallArr[y][x];

				int4 WallPos = { x, y };
				NewWall->SetPos(WallPos);
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(NewWall->GetPos(), GetRenderChar());
			}
		}
	}
}

void Map::DestroyWall(const int4& _Size)
{
	for (int y = 0; y < _Size.Y; y++)
	{
		for (int x = 0; x < _Size.X; x++)
		{
			if (WallArr[y][x] != nullptr)
			{
				delete WallArr[y][x];
				WallArr[y][x] = nullptr;
			}
		}

		if (WallArr[y] != nullptr)
		{
			delete[] WallArr[y];
			WallArr[y] = nullptr;
		}
	}

	if (WallArr != nullptr)
	{
		delete[] WallArr;
		WallArr = nullptr;
	}
}
