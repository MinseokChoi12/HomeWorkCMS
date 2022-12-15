#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"
#include <GameEngineArray.h>
//#include "Boom.h"

class Boom;
class ConsoleGameScreen;
class Player : public ConsoleGameObject
{
public:
	Player();
	~Player();

	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	bool Update();

private:
	int BoomUseCount = 0;
	GameEngineArray<Boom> ArrBoomObject;
};

