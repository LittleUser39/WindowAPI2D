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

void CMonster::Update() //���Ⱑ ���� �ൿ�� ���Ѱ�
{
	fPoint pos = GetPos();
	if (m_bIsUpDir)
	{
		pos.y -= m_fVelocity * DT;
		if (pos.y < m_fptCenterPos.y - m_fDistance)	//���� ���ϴ� ������ �� ���ΰ� - ������ �ٲ���
			m_bIsUpDir = false;
	}
	else
	{
		pos.y += m_fVelocity * DT;
		if (pos.y > m_fptCenterPos.y + m_fDistance)	//���� ���ϴ� ������ �� �Ʒ��ΰ� - ������ �ٲ���
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