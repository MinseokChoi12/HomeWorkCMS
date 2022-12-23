#pragma once
#include <ConsoleGameObject.h>

class Part : public ConsoleGameObject
{
public:
	Part();
	Part(wchar_t _RenderChar);
	~Part();

	Part(const Part& _Other) = delete;
	Part(Part&& _Other) noexcept = delete;
	Part& operator=(const Part& _Other) = delete;
	Part& operator=(Part&& _Other) noexcept = delete;

	virtual void Update();

	Part* GetBack() { return Back; }
	Part* GetFront() { return Front; }

	void SetBack(Part* _Part)
	{
		Back = _Part;
		Back->Front = this;
	}

	void RecursionFrontMove();
	void RecursionBackRender();

	Part* GetLastPart()
	{
		if (nullptr == Back)
			return this;

		return Back->GetLastPart();
	}

	int4 GetLastPartPos()
	{
		if (nullptr == Back)
			return int4{ 0 ,0 };

		return Back->GetLastPartPos();
	}

protected:
	Part* Front = nullptr;
	Part* Back = nullptr;

private:
};

