#include "ConsoleGameScreen.h"
#include <iostream>

//wchar_t ErrorChar = -1;
//wchar_t& ConsoleGameLine::operator[](size_t _Index)
//{
//	if (0 > _Index)
//	{
//		MessageBoxAssert("라인의 범위를 넘겨서 수정하려고 했습니다");
//		return ErrorChar;
//	}
//
//	if (XCount <= _Index)
//	{
//		MessageBoxAssert("라인의 범위를 넘겨서 수정하려고 했습니다");
//		return ErrorChar;
//	}
//
//	return Arr[_Index];
//}
//
//void ConsoleGameLine::Init(size_t _XCount, wchar_t _Char)
//{
//	if (Arr != nullptr)
//	{
//		MessageBoxAssert("라인을 두번 초기화 했습니다");
//		return;
//	}
//
//	Arr = new wchar_t[_XCount + 1]();
//
//	BaseChar = _Char;
//
//	for (size_t i = 0; i < _XCount; i++)
//	{
//		Arr[i] = BaseChar;
//	}
//
//	Arr[_XCount] = 0;
//
//	XCount = _XCount;
//}
//
//void ConsoleGameLine::Render()
//{
//	wprintf_s(Arr);
//}
//
//void ConsoleGameLine::Clear()
//{
//	for (size_t i = 0; i < XCount; i++)
//	{
//		Arr[i] = BaseChar;
//	}
//	Arr[XCount] = 0;
//}
//
//ConsoleGameLine::~ConsoleGameLine()
//{
//	if (Arr != nullptr)
//	{
//		delete[] Arr;
//		Arr = nullptr;
//	}
//}

///////////////////////////////////////////////////

ConsoleGameScreen* ConsoleGameScreen::MainScreen = nullptr;

ConsoleGameScreen::ConsoleGameScreen()
{
	MainScreen = this;
}

ConsoleGameScreen::~ConsoleGameScreen()
{
	/*if (Lines != nullptr)
	{
		delete[] Lines;
		Lines = nullptr;
	}*/
}

void ConsoleGameScreen::ScreenInit(const int4& _Size, wchar_t _Char)
{
	if (0 != Lines.GetCount())
	{
		MessageBoxAssert("스크린을 두번 초기화 했습니다");
		return;
	}

	setlocale(LC_ALL, "KOR");

	BaseChar = _Char;

	ScreenSize = _Size;

	Lines.ReSize(_Size.Y);

	for (size_t y = 0; y < Lines.GetCount(); y++)
	{
		Lines[y].ReSize(_Size.X + 1);

		for (size_t x = 0; x < Lines[y].GetCount(); x++)
		{
			Lines[y][x] = BaseChar;
		}
		Lines[y][_Size.X] = 0;
	}
}

void ConsoleGameScreen::SetPixelChar(int4 _Pos, wchar_t _Char)
{
	if (IsOver(_Pos) == true)
	{
		MessageBoxAssert("스크린의 바깐을 수정하려고 했습니다");
		return;
	}

	Lines[_Pos.Y][_Pos.X] = _Char;
}

void ConsoleGameScreen::ScreenRender()
{
	for (size_t y = 0; y < Lines.GetCount(); y++)
	{
		wprintf_s(&Lines[y][0]);
		wprintf_s(L"\n");
	}
}

void ConsoleGameScreen::ScreenClear()
{
	for (size_t y = 0; y < Lines.GetCount(); y++)
	{
		for (size_t x = 0; x < Lines[y].GetCount(); x++)
		{
			Lines[y][x] = BaseChar;
		}
		Lines[y][ScreenSize.X] = 0;
	}
}

bool ConsoleGameScreen::IsOver(int4 _Pos)
{
	if (0 > _Pos.X)
	{
		return true;
	}

	if (0 > _Pos.Y)
	{
		return true;
	}

	if (ScreenSize.X <= _Pos.X)
	{
		return true;
	}

	if (ScreenSize.Y <= _Pos.Y)
	{
		return true;
	}

	return false;
}
