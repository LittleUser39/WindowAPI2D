#pragma once
#include "CGameObject.h"
class CTextObj : public CGameObject
{
public:
	CTextObj();
	~CTextObj();
	virtual void Update();
	virtual void Render(HDC hDc);
	
};


