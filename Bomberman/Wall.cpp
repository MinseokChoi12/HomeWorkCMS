#include "Wall.h"
#include <conio.h>
#include <Windows.h>
#include "ConsoleGameScreen.h"

Wall** Wall::WallArr = nullptr;

Wall::Wall()
{
	WallArr = new Wall* [10]();
	SetRenderChar(L'��');
}

Wall::~Wall()
{
}

void Wall::CreateWall(const int4& _Size)
{
	for (int y = 0; y < _Size.Y; y++)
	{
		WallArr[y] = new Wall [15]();
		for (int x = 0; x < _Size.X; x++)
		{
			if (y % 2 == 1 && x % 2 == 1)
			{
				Wall& NewWall = WallArr[y][x];
				int4 WallPos = { x, y };
				NewWall.SetPos(WallPos);
				ConsoleGameScreen::GetMainScreen()->SetPixelChar(NewWall.GetPos(), GetRenderChar());
			}
		}
	}
}
