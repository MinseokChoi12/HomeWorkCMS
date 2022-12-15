#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"

class Wall : public ConsoleGameObject
{
public:
	Wall();
	~Wall();

	Wall(const Wall& _Other) = delete;
	Wall(Wall&& _Other) noexcept = delete;
	Wall& operator=(const Wall& _Other) = delete;
	Wall& operator=(Wall&& _Other) noexcept = delete;

private:
};

