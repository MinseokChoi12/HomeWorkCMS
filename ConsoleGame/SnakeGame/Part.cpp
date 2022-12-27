#include "Part.h"

void Part::DestroyPart(Part* _LastPart, Part* _StartPart)
{
	if (_LastPart->GetFront() == nullptr)
		return;

	if (_LastPart->GetFront() == _StartPart)
	{
		delete _LastPart;
		_LastPart = nullptr;

		return;
	}

	_LastPart = _LastPart->GetFront();
	delete _LastPart->GetBack();

	DestroyPart(_LastPart, _StartPart);
}

Part::Part()
{
}

Part::Part(wchar_t _RenderChar)
	: ConsoleGameObject(_RenderChar)
{
}

Part::~Part()
{
}

void Part::Update()
{
}

void Part::RecursionFrontMove()
{
	if (nullptr == Front)
		return;

	SetPos(Front->GetPos());

	return Front->RecursionFrontMove();
}

void Part::RecursionBackRender()
{
	Render();

	if (nullptr == Back)
		return;

	return Back->RecursionBackRender();
}
