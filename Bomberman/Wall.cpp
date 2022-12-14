#include "Wall.h"
#include <conio.h>
#include <Windows.h>
#include "ConsoleGameScreen.h"

Wall*** Wall::WallArr = nullptr;

Wall::Wall()
{	
	SetRenderChar(L'бс');
}

Wall::~Wall()
{
}

void Wall::CreateWall(const int4& _Size)
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
