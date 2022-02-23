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
	
	void SetDir(fVec2 vec);	//방향	세팅
	fVec2 GetDir(fVec2 vec);			//방향 반환
};

