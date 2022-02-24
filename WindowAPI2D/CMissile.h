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

	virtual void Update();
	
	void SetDir(fVec2 vec);		//방향	세팅
	void SetDir(float theta);   //방향에 각도가 들어갔을때
	fVec2 GetDir();				//방향 반환
};

