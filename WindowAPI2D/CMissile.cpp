#include "framework.h"
#include "CMissile.h"
#include "CCollider.h"

CMissile::CMissile()
{
	SetName(L"Missile");
	m_fVelocity = 100;
	m_fvDir = fVec2(0,0);
	SetScale(fPoint(20.f, 20.f));

	CreateCollider();	//충돌체 생성
	GetCollider()->SetScale(fPoint(10.f, 10.f));
}

CMissile::~CMissile()
{

}

CMissile* CMissile::Clone()
{
	return new CMissile(*this);
}

void CMissile::Update()
{
	fPoint pos = GetPos();
	
	pos.x += (float)m_fVelocity * m_fvDir.x * DT;
	pos.y += (float)m_fVelocity * m_fvDir.y * DT;
		
	SetPos(pos);
	
	
	if (pos.x < 0 || pos.x > WINSIZEX
		|| pos.y < 0 || pos.y > WINSIZEY)
		DeleteObj(this);
}

void CMissile::render(HDC hDc)
{
	fPoint pos = GetPos();
	fPoint scale = GetScale();

	fPoint fptRenderPos = CCameraManager::getInst()->GetRenderPos(pos);

	Ellipse(hDc,
		(int)(fptRenderPos.x - scale.x / 2.f),
		(int)(fptRenderPos.y - scale.y / 2.f),
		(int)(fptRenderPos.x + scale.x / 2.f),
		(int)(fptRenderPos.y + scale.y / 2.f));

	component_render(hDc);
}

void CMissile::SetDir(fVec2 vec)
{
	m_fvDir = vec.Nomarlize();
}


void CMissile::OnCollision(CCollider* pOther)
{
}
void CMissile::OnCollisionEnter(CCollider* pOther)
{
	CGameObject* pOtherObj = pOther->GetGameObject();
	if (pOtherObj->GetName() == L"Monster")
	{
		DeleteObj(this);
	}
}
void CMissile::OnCollisionExit(CCollider* pOther)
{

}
void CMissile::SetDir(float theta)
{
	m_fvDir.x = (float)cos(theta); //좌우는 코사인
	m_fvDir.y = (float)sin(theta); //위아래는 사인
}