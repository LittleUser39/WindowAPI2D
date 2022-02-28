#include "framework.h"
#include "CCollider.h"
#include "CGameObject.h"

#include "SelectGDI.h"

UINT CCollider::s_iID = 0;

CCollider::CCollider()
{
	m_pOwner = nullptr;
	m_iID = s_iID++;  //교유한 키값
	m_fptOffsetPos = {};
	m_fptFinalPos = {};
	m_fptScale = {};

	

}

CCollider::CCollider(const CCollider& other)
{
	m_pOwner = nullptr;
	m_fptOffsetPos = other.m_fptOffsetPos;
	m_fptFinalPos = other.m_fptFinalPos;
	m_fptScale = other.m_fptScale;
	m_iID = s_iID++;
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

UINT CCollider::Getid()
{
	return m_iID;
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

void CCollider::OnCollision(CCollider* pOther)
{
}

void CCollider::OnCollisionEnter(CCollider* pOther)
{
	
}

void CCollider::OnCollisionExit(CCollider* pOther)
{
	
}
