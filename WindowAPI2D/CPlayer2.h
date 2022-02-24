#pragma once
#include "CGameObject.h"
class CPlayer2 : public CGameObject
{
	double m_dVelocity;

public:
	CPlayer2();
	virtual ~CPlayer2();

	virtual void Update();
	virtual void Render(HDC hDc);

};

