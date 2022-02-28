#include "framework.h"
#include "CCollider.h"
#include "CGameObject.h"

#include "SelectGDI.h"

CCollider::CCollider()
{
	m_pOwner = nullptr;
}

CCollider::~CCollider()
{

}

fPoint CCollider::GetOffsetPos()
{
	return m_fptOffsetPos;
}

fPoint CCollider::GetFinalPos()
{
	return m_fptFinalPos;
}

fPoint CCollider::GetScale()
{
	return m_fptScale;
}

fPoint CCollider::SetOffsetPos(fPoint offset)
{
	return m_fptOffsetPos=offset;
}

fPoint CCollider::SetFinalPos(fPoint pos)
{
	return m_fptFinalPos=pos;
}

fPoint CCollider::SetScale(fPoint scale)
{
	return m_fptScale=scale;
}

void CCollider::finalUpdate()
{
	fPoint fptObjPos = m_pOwner->GetPos();
	m_fptFinalPos = fptObjPos + m_fptOffsetPos;
}

void CCollider::Render(HDC hDc)
{
	SelectGDI brush(hDc, TYPE_BRUSH::HOLLOW);
	SelectGDI pen(hDc, TYPE_PEN::GREEN);

	Rectangle(hDc,
		(int)(m_fptFinalPos.x - m_fptScale.x / 2.f),
		(int)(m_fptFinalPos.y - m_fptScale.y / 2.f),
		(int)(m_fptFinalPos.x + m_fptScale.x / 2.f),
		(int)(m_fptFinalPos.y + m_fptScale.y / 2.f));

	

}
