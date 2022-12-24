#include "Body.h"
#include <iostream>
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>
#include "Head.h"

Body* Body::CurBody = nullptr;

void Body::CreatBody(int4 _BodyPos)
{
    CurBody = new Body();
    
    CurBody->SetPos(_BodyPos);
}

int4 Body::EmptyPos(Part* _CurPart, int4 _BodyPos)
{
    int4 CurPartPos = _CurPart->GetPos();
    if (_CurPart != nullptr && _BodyPos == CurPartPos)
        return int4{ -1, -1 };

    if (_CurPart->GetBack() == nullptr)
        return _BodyPos;
   
    EmptyPos(_CurPart->GetBack(), _BodyPos);
}

Body* Body::GetCurBody()
{
    return CurBody;
}

Body::Body()
    : Part(L'¡Ú')
{
}

Body::~Body()
{
}

void Body::Update()
{
    if (true == GameEngineInput::GetIsInput())
    {
        if (nullptr == GetFront())
            return;

        SetPos(GetFront()->GetPos());
    }
}

