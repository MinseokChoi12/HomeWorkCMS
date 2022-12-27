#pragma once
#include <ConsoleGameObject.h>

class Part : public ConsoleGameObject
{
public:
	static void DestroyPart(Part* _LastPart, Part* _StartPart);

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

protected:
	Part* Front = nullptr;
	Part* Back = nullptr;

private:
};

