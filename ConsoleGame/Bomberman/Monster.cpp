#include "Monster.h"
#include "ConsoleGameScreen.h"
#include "Wall.h"
#include "Boom.h"

GameEngineArray<Monster> Monster::AllMonster(10);
size_t Monster::MonsterUpdateCount = 0;

void  Monster::AllMonsterInit(wchar_t _BaseChar)
{
	for (size_t i = 0; i < AllMonster.GetCount(); i++)
	{
		AllMonster[i].Off();
		AllMonster[i].SetRenderChar(_BaseChar);
	}
}

Monster* Monster::CreateMonster(int4 _Pos, int4 _Dir)
{
	Monster* ReturnMonster = &AllMonster[MonsterUpdateCount];
	AllMonster[MonsterUpdateCount].SetPos(_Pos);
	AllMonster[MonsterUpdateCount].SetDir(_Dir);
	AllMonster[MonsterUpdateCount++].On();

	return ReturnMonster;
}

void Monster::AllMonsterUpdate()
{
	for (size_t i = 0; i < AllMonster.GetCount(); i++)
	{
		if (false == AllMonster[i].GetIsUpdate())
			continue;

		AllMonster[i].Update();
	}
}

GameEngineArray<Monster>* Monster::GetAllMonster()
{
	return &AllMonster;
}

bool Monster::GetIsMonster(int4 _Size)
{
	for (size_t i = 0; i < AllMonster.GetCount(); i++)
	{
		if (_Size == AllMonster[i].GetPos())
		{
			return true;
		}
	}
	return false;
}


Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::Init()
{

}

void Monster::Update()
{
	int4 Pos = GetPos();
	int4 MovePos = Pos + Dir;

	if (ConsoleGameScreen::GetMainScreen()->IsOver(MovePos))
	{
		Dir.X *= -1;
		Dir.Y *= -1;
	}

	const int4 NextPos = Pos + Dir;
	
	SetPos(NextPos);
	Render();
}
