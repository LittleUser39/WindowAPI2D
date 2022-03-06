#pragma once
#include "CGameObject.h"
class CMonster : public CGameObject
{
	fPoint m_fptCenterPos;	//�߰� ��ǥ
	float m_fVelocity ;		// ������ �ӵ�
	float m_fDistance;		// ���Ͱ� ������ �Ÿ�
	bool m_bIsUpDir;		// ��,�Ʒ��� ���� �ִ°�
	CTexture* m_pTex;
public:
	CMonster();
	virtual  ~CMonster();
	virtual CMonster* Clone();

	virtual void Render(HDC hDc);
	virtual void Update();		//������ �ൿ ����
	void SetCenterPos(fPoint point);	//�߰� ��ǥ ����
	fPoint GetCenterPos();		//�߰� ��ǥ ��������


	//�浹 ���� �Լ�
	virtual void OnCollision(CCollider* pOther);
	virtual void OnCollisionEnter(CCollider* pOther);
	virtual void OnCollisionExit(CCollider* pOther);
};

