#pragma once
#include "Part.h"

class Head : public Part
{
public:
	static bool GetGameOver() { return GameOver; };
	

	Head();
	~Head();

	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;


protected:
	void Update() override;

private:
	bool IsBody(Part* _Part,int4 _NextPos);
	static Head* CurHead;
	static bool GameOver;
};

