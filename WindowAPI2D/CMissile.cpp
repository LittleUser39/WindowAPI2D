#include "framework.h"
#include "CMissile.h"
#include "CCollider.h"

CMissile::CMissile()
{
	SetName(L"Missile");
	m_fVelocity = 300;
	m_fvDir = fVec2(0,0);
	SetScale(fPoint(20.f, 20.f));

	CreateCollider();	//�浹ü ����
	GetCollider()->SetScale(fPoint(10.f, 10.f));
}

CMissile::~CMissile()
{

}

void CMissile::Update()
{
	fPoint pos = GetPos();
	
	pos.x += (float)m_fVelocity * m_fvDir.x * DT;
	pos.y += (float)m_fVelocity * m_fvDir.y * DT;
		
	SetPos(pos);
	
	//�ϴ� �̰Ŷ����� ���� 
	/*if (pos.x < 0 || pos.x > WINSIZEX
		|| pos.y < 0 || pos.y > WINSIZEY)
		DeleteObj(this);*/
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