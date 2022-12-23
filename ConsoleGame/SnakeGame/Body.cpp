#include "Body.h"
#include <iostream>
#include <ConsoleGameScreen.h>
#include <GameEngineInput.h>
#include "Head.h"

Body* Body::CurBody = nullptr;

void Body::CreatBody()
{
    srand(time(nullptr));
    CurBody = new Body();
    int Body_X = rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().X;
    int Body_Y = rand() % ConsoleGameScreen::GetMainScreen()->GetScreenSize().Y;

    int4 BodyPos = { Body_X, Body_Y };

    Part* CurPart = Head::GetCurHead();
    int4 CurPartPos = CurPart->GetPos();
    
    if (IsEmpty(CurPart, BodyPos))
        CurBody->SetPos(BodyPos);
    else
    {
        delete CurBody;
        CurBody = nullptr;
        CreatBody();
    } 
}

bool Body::IsEmpty(Part* _CurPart, int4 _BodyPos)
{
    int4 CurPartPos = _CurPart->GetPos();
    if (_CurPart != nullptr && _BodyPos == CurPartPos)
        return false;

    if (_CurPart->GetBack() == nullptr)
        return true;
   
    IsEmpty(_CurPart->GetBack(), _BodyPos);
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

