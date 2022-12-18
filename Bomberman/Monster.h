#pragma once
#include "ConsoleGameMath.h"
#include "ConsoleGameObject.h"
#include "GameEngineArray.h"
class Monster : public ConsoleGameObject
{
public:
	static size_t MonsterUpdateCount;
	static Monster* CreateMonster(int4 _Pos, int4 _Dir);
	static void AllMonsterInit(wchar_t _BaseChar);
	static void AllMonsterUpdate();
	static GameEngineArray<Monster>* GetAllMonster();
	static bool GetIsMonster(int4 _Size);

	Monster();
	~Monster();

	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;

	Monster& operator=(const Monster& _Other) { return *this; }
	void SetDir(int4 _Dir) { Dir = _Dir; }

	void Update();

protected:

private:
	static GameEngineArray<Monster> AllMonster;
	int4 Dir;
	void Init();
};

