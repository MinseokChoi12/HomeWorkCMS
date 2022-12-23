#include "Part.h"

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
