#pragma once
#include "Part.h"

class Head : public Part
{
public:
	static Head* GetCurHead();

	Head();
	~Head();

	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

protected:
	void Update() override;

private:
	static Head* CurHead;
};

