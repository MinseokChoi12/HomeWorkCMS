#pragma once
class int4
{
public:
	static const int4 LEFT;
	static const int4 RIGHT;
	static const int4 UP;
	static const int4 DOWN;

public:
	int X = 0;
	int Y = 0;
	int Z = 0;
	int W = 0;

	int4& operator+=(const int4& _Value)
	{
		X += _Value.X;
		Y += _Value.Y;
		Z += _Value.Z;
		W += _Value.W;

		return *this;
	}

	int4& operator+(const int4& _Value1)
	{
		int4 POS;
		POS.X = this->X + _Value1.X;
		POS.Y = this->Y + _Value1.Y;
		POS.Z = this->Z + _Value1.Z;
		POS.W = this->W + _Value1.W;

		return POS;
	}

	int4& operator*(const int num)
	{				
		X *= num;
		Y *= num;
		Z *= num;
		W *= num;

		return *this;
	}

	bool operator==(const int4& _Value)
	{
		return X == _Value.X && Y == _Value.Y;
	}

	bool operator!=(const int4& _Value)
	{
		return !(X == _Value.X && Y == _Value.Y);
	}
};

