#include "framework.h"
#include "CMissile.h"
#include "CCollider.h"

CMissile::CMissile()
{
	m_fVelocity = 300;
	m_fvDir = fVec2(0,0);
	SetScale(fPoint(10, 10));
	CreateCollider();	//충돌체 생성
	GetCollider()->SetScale(fPoint(10, 10));
}

CMissile::~CMissile()
{

}

void CMissile::Update()
{
	fPoint pos = GetPos();
	//todo 대각선을 구현하고 쏨 
	pos.x += (float)m_fVelocity * m_fvDir.x * DT;
	pos.y += (float)m_fVelocity * m_fvDir.y * DT;
		
	SetPos(pos);
}

void CMissile::SetDir(fVec2 vec)
{
	m_fvDir = vec.Nomarlize();
}

fVec2 CMissile::GetDir()
{
	return m_fvDir;
}
void CMissile::SetDir(float theta)
{
	m_fvDir.x = (float)cos(theta); //좌우는 코사인
	m_fvDir.y = (float)sin(theta); //위아래는 사인
}