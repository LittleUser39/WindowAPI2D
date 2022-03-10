#pragma once
#include "CGameObject.h"
class CTexture;
class Mario : public CGameObject
{
	float m_dVelocity;	//그냥 속도
	float m_UpSpeed;	//점프 속도
	float m_gravite;	//중력

	CTexture* m_pTex;	//이미지 파일

	bool Isfly;			//캐릭터가 하늘에 있는지
	bool IsRight;		//방향전환

public:
	Mario();
	virtual ~Mario();

	virtual Mario* Clone();

	virtual void Update();
	virtual void Render(HDC hDc);

	void CreateMissile(); // 미사일을 만드는 함수

	//충돌 시점 함수
	virtual void OnCollision(CCollider* pOther);
	virtual void OnCollisionEnter(CCollider* pOther);
	virtual void OnCollisionExit(CCollider* pOther);
};

