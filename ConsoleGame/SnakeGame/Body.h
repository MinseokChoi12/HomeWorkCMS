#pragma once
#include "Part.h"

class Body : public Part
{
public:
	static void CreatBody(int4 _BodyPos);
	static Body* GetCurBody();
	static int4 EmptyPos(Part* _CurPart, int4 _BodyPos);

	~Body();

	Body(const Body& _Other) = delete;
	Body(Body&& _Other) noexcept = delete;
	Body& operator=(const Body& _Other) = delete;
	Body& operator=(Body&& _Other) noexcept = delete;

	void Update() override;

protected:

private:
	Body();
	static Body* CurBody;
};

