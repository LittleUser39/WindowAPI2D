#pragma once
#include "CGameObject.h"
class CMissile : public CGameObject
{
private:
	fVec2 m_fvDir;
	float m_fVelocity;	//미사일 속도
	
public:
	CMissile();
	~CMissile();
	
	virtual CMissile* Clone();

	virtual void Update();
	virtual void render(HDC hDc);

	void SetDir(fVec2 vec);		//방향	세팅
	void SetDir(float theta);   //방향에 각도가 들어갔을때
	

		//충돌 시점 함수
	virtual void OnCollision(CCollider* pOther);
	virtual void OnCollisionEnter(CCollider* pOther);
	virtual void OnCollisionExit(CCollider* pOther);
};

