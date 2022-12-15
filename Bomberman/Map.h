#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"

class Wall;
class Map : public ConsoleGameObject
{
public:
	Map();
	~Map();

	Map(const Map& _Other) = delete;
	Map(Map&& _Other) noexcept = delete;
	Map& operator=(const Map& _Other) = delete;
	Map& operator=(Map&& _Other) noexcept = delete;

	void CreateWall(const int4& _Size);
	void DestroyWall(const int4& _Size);

	static Wall*** GetWallArr() { return WallArr; }

private:
	static Wall*** WallArr;

};

