#include "framework.h"
#include "CMonster.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimation.h"
#include "CAnimator.h"

CMonster::CMonster()
{
	SetScale(fPoint(200, 200));
	m_fVelocity = 300;	//������ �ӵ�
	m_fDistance = 200;	//������ �Ÿ�
	m_bIsUpDir	= true;
	

	CreateCollider();
	GetCollider()->SetScale(fPoint(200, 200));
}

CMonster::~CMonster()
{

}

CMonster* CMonster::Clone()
{
	return new CMonster(*this);
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

	GetAnimator()->Update();
}

void CMonster::SetCenterPos(fPoint point)
{
	m_fptCenterPos = point;
}

void CMonster::Render(HDC hDc)
{
	int width = m_pTex->GetBmpWidth();
	int height = m_pTex->GetBmpHeight();

	/*TransparentBlt(hDc,
		(int)(GetPos().x - (float)(width / 2)),
		(int)(GetPos().y - (float)(height / 2)),
		width, height,
		m_pTex->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255));*/
	
	component_render(hDc);
}

fPoint CMonster::GetCenterPos()
{
	return m_fptCenterPos;
}

void CMonster::OnCollision(CCollider* pOther)
{
}

void CMonster::OnCollisionEnter(CCollider* pOther)
{
}

void CMonster::OnCollisionExit(CCollider* pOther)
{
}
