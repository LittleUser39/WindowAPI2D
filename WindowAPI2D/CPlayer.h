#pragma once
#include "CGameObject.h"
class CPlayer : public CGameObject
{
	double m_dVelocity;
	
public:
	CPlayer();
	virtual ~CPlayer();

	virtual void Update();
	virtual void Render(HDC hDc);

	void CreateMissile(); // 미사일을 만드는 함수
};

