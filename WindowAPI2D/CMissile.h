#pragma once
#include "CGameObject.h"
class CMissile : public CGameObject
{
private:
	float m_fVelocity;	//�̻��� �ӵ�
	bool m_bIsRightDir;	//�̻��� ����
public:
	CMissile();
	~CMissile();

	virtual void Update();
};

