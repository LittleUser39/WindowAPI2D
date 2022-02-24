#pragma once
#include "CGameObject.h"
class CBall : public CGameObject
{
	fPoint m_fptPos;			//위치 값
	fPoint m_fptScale;			//크기 값
public:

	int rando()
	{
		srand(time(NULL));
		return (rand() % 4);
	}

	virtual void Update();
	virtual void Render(HDC hDc);
};

