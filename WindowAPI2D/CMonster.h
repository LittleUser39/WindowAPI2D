#pragma once
#include "CGameObject.h"
class CMonster : public CGameObject
{
	fPoint m_fptCenterPos;	//중간 좌표
	float m_fVelocity ;		// 몬스터의 속도
	float m_fDistance;		// 몬스터가 움직일 거리
	bool m_bIsUpDir;		// 위,아래로 가고 있는가

public:
	CMonster();
	virtual  ~CMonster();

	virtual void Update();		//몬스터의 행동 구성
	void SetCenterPos(fPoint point);	//중간 좌표 설정
	fPoint GetCenterPos();		//중간 좌표 가져오기

};

