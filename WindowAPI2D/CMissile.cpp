#include "framework.h"
#include "CMissile.h"

CMissile::CMissile()
{
	m_fVelocity = 500;
	
	SetScale(fPoint(10, 10));
}

CMissile::~CMissile()
{

}

void CMissile::Update()
{
	fPoint pos = GetPos();
	//todo 대각선을 구현하고 쏨
	pos.x += (float)m_fVelocity * m_fvDir.x * DT;
	pos.y += (float)m_fVelocity * m_fvDir.x * DT;
	
	SetPos(pos);
}

void CMissile::SetDir(fVec2 vec)
{
	m_fvDir = vec;
}

fVec2 CMissile::GetDir(fVec2 vec)
{
	return vec;
}
