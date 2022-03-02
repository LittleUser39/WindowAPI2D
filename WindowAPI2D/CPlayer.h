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

	void CreateMissile(); // 미사일을 만드는 함수

		//충돌 시점 함수
	virtual void OnCollision(CCollider* pOther);
	virtual void OnCollisionEnter(CCollider* pOther);
	virtual void OnCollisionExit(CCollider* pOther);
};

