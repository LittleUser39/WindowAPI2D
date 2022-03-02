#include "framework.h"
#include "CGameObject.h"
#include "CCollider.h"

void CGameObject::SetDead()
{
	m_bAllive = false;
}

CGameObject::CGameObject()
{
	m_fptPos = {};
	m_fptScale = {};
	m_pCollider = nullptr;
	m_bAllive = true;
}

CGameObject::~CGameObject()
{
	if (nullptr != m_pCollider)
	{
		delete m_pCollider;
	}
}

void CGameObject::Update()
{
	
}

void CGameObject::finalUpdate()
{
	if (nullptr != m_pCollider)	//충돌체가 있다
	{	
		m_pCollider->finalUpdate();	//충돌
	}
}

void CGameObject::Render(HDC hDc)
{
	Rectangle(hDc,
		(int)(GetPos().x - GetScale().x / 2),
		(int)(GetPos().y - GetScale().y / 2),
		(int)(GetPos().x + GetScale().x / 2),
		(int)(GetPos().y + GetScale().y / 2));
	
	component_render(hDc);
}

void CGameObject::component_render(HDC hDc)
{
	if (nullptr != m_pCollider)
	{
		m_pCollider->Render(hDc);
	}
}

void CGameObject::SetPos(fPoint pos)
{
	m_fptPos = pos;
}

void CGameObject::SetScale(fPoint scale)
{
	m_fptScale = scale;
}

void CGameObject::SetName(wstring name)
{
	m_strName = name;
}

wstring CGameObject::GetName()
{
	return m_strName;
}

void CGameObject::CreateCollider()
{
	m_pCollider = new CCollider();
	m_pCollider->m_pOwner = this;

}

bool CGameObject::isDead()
{
	return !m_bAllive;
}

fPoint CGameObject::GetPos()
{
	return m_fptPos;
}

fPoint CGameObject::GetScale()
{
	return m_fptScale;
}

CCollider* CGameObject::GetCollider()
{
	return m_pCollider;
}
