#pragma once
#include "CGameObject.h"
class CTexture;
class CPlayer : public CGameObject
{
	float m_dVelocity;
	CTexture* m_pTex;
	float m_gravite;
	fPoint m_directspeed;
	float m_UpSpeed;
	bool Isfly;

public:
	CPlayer();
	virtual ~CPlayer();

	virtual CPlayer* Clone();

	virtual void Update();
	virtual void Render(HDC hDc);

	void CreateMissile(); // �̻����� ����� �Լ�

	//�浹 ���� �Լ�
	virtual void OnCollision(CCollider* pOther);
	virtual void OnCollisionEnter(CCollider* pOther);
	virtual void OnCollisionExit(CCollider* pOther);
};

