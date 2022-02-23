#pragma once
#include "CGameObject.h"
class CMonster : public CGameObject
{
	fPoint m_fptCenterPos;	//�߰� ��ǥ
	float m_fVelocity ;		// ������ �ӵ�
	float m_fDistance;		// ���Ͱ� ������ �Ÿ�
	bool m_bIsUpDir;		// ��,�Ʒ��� ���� �ִ°�

public:
	CMonster();
	virtual  ~CMonster();

	virtual void Update();		//������ �ൿ ����
	void SetCenterPos(fPoint point);	//�߰� ��ǥ ����
	fPoint GetCenterPos();		//�߰� ��ǥ ��������

};

