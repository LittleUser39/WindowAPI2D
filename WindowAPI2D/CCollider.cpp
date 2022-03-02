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
	m_iCollCount = 0;
}

CCollider::CCollider(const CCollider& other)
{
	m_pOwner = nullptr;
	m_fptOffsetPos = other.m_fptOffsetPos;
	m_fptFinalPos = other.m_fptFinalPos;
	m_fptScale = other.m_fptScale;
	m_iID = s_iID++;
	m_iCollCount = other.m_iCollCount;
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
	TYPE_PEN pen_Color;
	if (m_bIsCollsing)
		pen_Color = TYPE_PEN::RED;
	else
		pen_Color = TYPE_PEN::GREEN;

	SelectGDI brush(hDc, TYPE_BRUSH::HOLLOW);
	SelectGDI pen(hDc, pen_Color);


	Rectangle(hDc,
		(int)(m_fptFinalPos.x - m_fptScale.x / 2.f),
		(int)(m_fptFinalPos.y - m_fptScale.y / 2.f),
		(int)(m_fptFinalPos.x + m_fptScale.x / 2.f),
		(int)(m_fptFinalPos.y + m_fptScale.y / 2.f));
}

void CCollider::OnCollision(CCollider* pOther)		//충돌중
{
	m_pOwner->OnCollision(pOther);
}

void CCollider::OnCollisionEnter(CCollider* pOther)	//충돌에 들어감
{
	m_bIsCollsing = true;
	/*m_pOwner->OnCollisionEnter(pOther);
	m_iCollCount++;*/
}

void CCollider::OnCollisionExit(CCollider* pOther)	//충돌에 벗어남
{
	m_bIsCollsing = false;
	/*m_pOwner->OnCollisionExit(pOther);
	m_iCollCount--;*/
}
