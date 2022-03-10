#pragma once
#include "CGameObject.h"
class CBackGround : public CGameObject
{
	CTexture* m_pTex;

public:
	CBackGround();
	~CBackGround();

	void Render(HDC hDc);
	virtual void Update();
	virtual CGameObject* Clone();
};


