#pragma once
#include "CGameObject.h"
class CMissile : public CGameObject
{
private:
	float m_fVelocity;	//미사일 속도
	bool m_bIsRightDir;	//미사일 방향
public:
	CMissile();
	~CMissile();

	virtual void Update();
};

