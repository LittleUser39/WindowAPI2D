#pragma once
#include "CGameObject.h"
class CTexture;
class CPlayer : public CGameObject
{
	double m_dVelocity;
	CTexture* m_pTex;
public:
	CPlayer();
	virtual ~CPlayer();

	virtual void Update();
	virtual void Render(HDC hDc);

	void CreateMissile(); // �̻����� ����� �Լ�

		//�浹 ���� �Լ�
	virtual void OnCollision(CCollider* pOther);
	virtual void OnCollisionEnter(CCollider* pOther);
	virtual void OnCollisionExit(CCollider* pOther);
};

