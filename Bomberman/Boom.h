#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"
#include <GameEngineArray.h>
// 
class ConsoleGameScreen;
class Player;
class Boom : public ConsoleGameObject
{
public:
	static void BoomMapInit(int4 _Size);
	static void MapClear();
	static Boom* GetBoom(int4 _Size);

	Boom();
	~Boom();

	Boom(const Boom& _Other) = delete;
	Boom(Boom&& _Other) noexcept = delete;
	Boom& operator=(const Boom& _Other)
	{
		Time = _Other.Time;
		Range = _Other.Range;

		return *this;
	}

	Boom& operator=(Boom&& _Other) noexcept = delete;

	void Update();

	bool IsDeath()
	{
		return 0 > Time;
	}

private:
	static GameEngineArray<GameEngineArray<Boom*>>	BoomMap;

	int Time = 20;
	int CurRange = 0;
	int Range = 4;
};

