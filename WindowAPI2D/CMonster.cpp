#include "framework.h"
#include "CMonster.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimation.h"
#include "CAnimator.h"

CMonster::CMonster()
{
	SetName(L"Gumba");
	m_pTex = CResourceManager::getInst()->LoadTexture(L"MonsterTex", L"\\texture\\Goom.bmp");

	SetScale(fPoint(70, 70));
	m_fVelocity = 300;
	m_fDistance = 200;
	m_bIsUpDir	= true;
	

	CreateCollider();
	GetCollider()->SetScale(fPoint(50, 50));
}

CMonster::~CMonster()
{
}

CMonster* CMonster::Clone()
{
	return new CMonster(*this);
}



void CMonster::Update() //여기가 몬스터 행동에 관한것
{
	fPoint pos = GetPos();
	//if (m_bIsUpDir)
	//{
	//	pos.y -= m_fVelocity * DT;
	//	if (pos.y < m_fptCenterPos.y - m_fDistance)	//내가 원하는 곳에서 더 위로감 - 방향을 바꿔줌
	//		m_bIsUpDir = false;
	//}
	//else
	//{
	//	pos.y += m_fVelocity * DT;
	//	if (pos.y > m_fptCenterPos.y + m_fDistance)	//내가 원하는 곳에서 더 아래로감 - 방향을 바꿔줌
	//		m_bIsUpDir = true;
	//
	//}

	SetPos(pos);
}

void CMonster::SetCenterPos(fPoint point)
{
	m_fptCenterPos = point;
}

void CMonster::Render(HDC hDc)
{
	int width = m_pTex->GetBmpWidth();
	int height = m_pTex->GetBmpHeight();

	TransparentBlt(hDc,
		(int)(GetPos().x - (float)(width / 2)),
		(int)(GetPos().y - (float)(height / 2)),
		width, height,
		m_pTex->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255));
	
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
