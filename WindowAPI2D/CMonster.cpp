#include "framework.h"
#include "CMonster.h"

CMonster::CMonster()
{
	SetScale(fPoint(200, 200));
	m_fVelocity = 300;
	m_fDistance = 200;
	m_bIsUpDir	= true;

}

CMonster::~CMonster()
{
}

void CMonster::Update() //여기가 몬스터 행동에 관한것
{
	fPoint pos = GetPos();
	if (m_bIsUpDir)
	{
		pos.y -= m_fVelocity * DT;
		if (pos.y < m_fptCenterPos.y - m_fDistance)	//내가 원하는 곳에서 더 위로감 - 방향을 바꿔줌
			m_bIsUpDir = false;
	}
	else
	{
		pos.y += m_fVelocity * DT;
		if (pos.y > m_fptCenterPos.y + m_fDistance)	//내가 원하는 곳에서 더 아래로감 - 방향을 바꿔줌
			m_bIsUpDir = true;

	}

	SetPos(pos);
}

void CMonster::SetCenterPos(fPoint point)
{
	m_fptCenterPos = point;
}

fPoint CMonster::GetCenterPos()
{
	return m_fptCenterPos;
}
