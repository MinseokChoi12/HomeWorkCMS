#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"

class Splash : public ConsoleGameObject
{
	Splash();
	~Splash();

	Splash(const Splash& _Other) = delete;
	Splash(Splash&& _Other) noexcept = delete;
	Splash& operator=(const Splash& _Other) = delete;
	Splash& operator=(Splash&& _Other) noexcept = delete;

	void Update();
};

