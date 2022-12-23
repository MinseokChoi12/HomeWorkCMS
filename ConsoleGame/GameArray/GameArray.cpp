#include <iostream>
#include "GameEngineArray.h"

int main()
{
	LeckCheck();

	GameEngineArray<int*> NewArray(10);

	NewArray.ReSize(20);

	NewArray.ReSize(30);

	NewArray.ReSize(40);
}