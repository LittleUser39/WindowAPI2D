#include "framework.h"
#include "CMissile.h"

CMissile::CMissile()
{
	m_fVelocity = 500;
	m_bIsRightDir = true;
	SetScale(fPoint(10, 10));
}

CMissile::~CMissile()
{

}

void CMissile::Update()
{
	fPoint pos = GetPos();
	if (m_bIsRightDir)
	{
		pos.x += m_fVelocity * DT;
	}
	else
	{
		pos.x -= m_fVelocity * DT;
	}

	SetPos(pos);
}
