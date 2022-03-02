#include "framework.h"
#include "CMissile.h"
#include "CCollider.h"

CMissile::CMissile()
{
	SetName(L"Missile");
	m_fVelocity = 300;
	m_fvDir = fVec2(0,0);
	SetScale(fPoint(10, 10));

	CreateCollider();	//�浹ü ����
	GetCollider()->SetScale(fPoint(10, 10));
}

CMissile::~CMissile()
{

}

void CMissile::Update()
{
	fPoint pos = GetPos();
	//todo �밢���� �����ϰ� �� 
	pos.x += (float)m_fVelocity * m_fvDir.x * DT;
	pos.y += (float)m_fVelocity * m_fvDir.y * DT;
		
	SetPos(pos);
	
	
}

void CMissile::render(HDC hDc)
{
	fPoint pos = GetPos();
	fPoint scale = GetScale();


	Ellipse(hDc,
		(int)(pos.x - scale.x / 2.f),
		(int)(pos.y - scale.y / 2.f),
		(int)(pos.x + scale.x / 2.f),
		(int)(pos.y + scale.y / 2.f));

	component_render(hDc);
}

void CMissile::SetDir(fVec2 vec)
{
	m_fvDir = vec.Nomarlize();
}

fVec2 CMissile::GetDir()
{
	return m_fvDir;
}
void CMissile::OnCollision(CCollider* pOther)
{
}
void CMissile::OnCollisionEnter(CCollider* pOther)
{
	
}
void CMissile::OnCollisionExit(CCollider* pOther)
{

}
void CMissile::SetDir(float theta)
{
	m_fvDir.x = (float)cos(theta); //�¿�� �ڻ���
	m_fvDir.y = (float)sin(theta); //���Ʒ��� ����
}