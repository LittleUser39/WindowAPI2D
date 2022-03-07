#include "framework.h"
#include "CMonster.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimation.h"
#include "CAnimator.h"

CMonster::CMonster()
{
	SetName(L"Goomba");
	m_pTex = CResourceManager::getInst()->LoadTexture(L"MonsterTex", L"\\texture\\Animation\\Goomba.bmp");

	SetScale(fPoint(30, 30));
	m_fVelocity = 50;
	m_fDistance = 100;
	m_bIsUpDir	= true;
	

	CreateCollider();
	GetCollider()->SetScale(fPoint(20, 20));
	
	CreateAnimator();						//이름 속성 시작위치 자를위치 속도,이건 애니메 갯수
	//GetAnimator()->CreateAnimation(L"Idle", m_pTex, fPoint(0.f, 0.f), fPoint(60.f, 60.f), fPoint(60.f, 0.f), 0.25f, 1);
	GetAnimator()->CreateAnimation(L"Left_Move", m_pTex, fPoint(0.f, 0.f), fPoint(60.f, 60.f), fPoint(60.f, 0.f), 0.25f, 2);
	GetAnimator()->CreateAnimation(L"Right_Move", m_pTex, fPoint(240.f, 0.f), fPoint(60.f, 60.f), fPoint(60.f, 0.f), 0.25f, 2);
	//GetAnimator()->Play(L"Left_Move");
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
	if (m_bIsUpDir)
	{
		pos.x -= m_fVelocity * DT;
		if (pos.x < m_fptCenterPos.x - m_fDistance)	
			m_bIsUpDir = false;
		GetAnimator()->Play(L"Left_Move");
	}
	else
	{
		pos.x += m_fVelocity * DT;
		if (pos.x > m_fptCenterPos.x + m_fDistance)	
			m_bIsUpDir = true;
		GetAnimator()->Play(L"Right_Move");
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
