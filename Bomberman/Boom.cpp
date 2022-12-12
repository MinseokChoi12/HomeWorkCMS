#include "Boom.h"
#include <conio.h>
#include "ConsoleGameScreen.h"
#include "Player.h"
#include <Windows.h>

Boom::Boom()
{
	SetRenderChar(L'��');
}

Boom::~Boom()
{
}

void Boom::Update()
{
	
	if (0 > --Time)
	{
		for (size_t i = 1; i <= Range; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				int4 unitPos[4] = { {0,-1}, {1,0}, {0,1}, {-1,0} };
				int4 Pos = GetPos() + unitPos[j] * i;
				if(ConsoleGameScreen::GetMainScreen()->IsOver(Pos) != true)
					ConsoleGameScreen::GetMainScreen()->SetPixelChar(Pos, L'��');
			}			
		}

	
		
		return;
	}

	ConsoleGameScreen::GetMainScreen()->SetPixelChar(GetPos(), GetRenderChar());
}