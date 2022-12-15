#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"
#include <GameEngineArray.h>

class ConsoleGameScreen;
class Player;
class Wall : public ConsoleGameObject
{
public:
	static void WallMapInit(int4 _Size);
	static void WallUpdata();
	static bool GetIsWall(int4 _Size);

	Wall();
	~Wall();

	Wall(const Wall& _Other) = delete;
	Wall(Wall&& _Other) noexcept = delete;

	Wall& operator=(const Wall& _Other)
	{
		return *this;
	}

	Wall& operator=(Wall&& _Other) noexcept = delete;

	void Updata();

protected:
	bool IsWall;

private:
	static GameEngineArray<GameEngineArray<Wall>> WallMap;
};

