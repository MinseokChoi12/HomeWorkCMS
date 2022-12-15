#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"
#include <GameEngineArray.h>

class ConsoleGameScreen;
class Player;
class Monster : public ConsoleGameObject
{
public:
	Monster();
	~Monster();

	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;

	void Update(int4 _Size, int _num);

protected:

private:
	float Time = 0.0f;
	float dir = 1.0f;
};

