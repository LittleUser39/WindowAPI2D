#pragma once
#include "CScene.h"
class CScene_Tool : public CScene
{
public:
    CScene_Tool();
    ~CScene_Tool();

    virtual void Update();

    virtual void Enter();
    virtual void Exit();
};

