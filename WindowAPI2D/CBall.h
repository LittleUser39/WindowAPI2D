#pragma once
#include "CGameObject.h"
class CBall : public CGameObject
{
	fPoint m_fptPos;			//��ġ ��
	fPoint m_fptScale;			//ũ�� ��
public:

	int rando()
	{
		srand(time(NULL));
		return (rand() % 4);
	}

	virtual void Update();
	virtual void Render(HDC hDc);
};

