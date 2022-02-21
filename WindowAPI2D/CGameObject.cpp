#include "framework.h"
#include "CGameObject.h"

CGameObject::CGameObject()
{
}

CGameObject::CGameObject(fPoint pos, fPoint scale)
{
	m_fptPos = pos;
	m_fptScale = scale;
}

CGameObject::~CGameObject()
{
}

void CGameObject::Render(HDC hDc)
{
	//todo 지워야함
	Rectangle(hDc,
		m_fptPos.x - m_fptScale.x / 2,
		m_fptPos.y - m_fptScale.y / 2,
		m_fptPos.x + m_fptScale.x / 2,
		m_fptPos.y + m_fptScale.y / 2);
}

void CGameObject::SetPos(fPoint pos)
{
	m_fptPos = pos;
}

void CGameObject::SetScale(fPoint scale)
{
	m_fptScale = scale;
}

fPoint CGameObject::GetPos()
{
	return m_fptPos;
}

fPoint CGameObject::GetScale()
{
	return m_fptScale;
}