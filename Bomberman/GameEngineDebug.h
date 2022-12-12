#pragma once
#include <Windows.h>
#include <assert.h>

class GameEngineDebug
{
public:
	GameEngineDebug();
	~GameEngineDebug();

	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;


};

void LeckCheck();

#define MessageBoxAssert(MsgText) MessageBoxA(nullptr, MsgText, "Error", MB_OK);	assert(false);

