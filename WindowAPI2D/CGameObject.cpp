#include "framework.h"
#include "CGameObject.h"
#include "CCollider.h"
#include "CAnimator.h"

CGameObject::CGameObject()
{
	m_fptPos	= {};
	m_fptScale	= {};
	m_pCollider = nullptr;
	m_pAnimator = nullptr;
	m_bAlive	= true;
}

CGameObject::CGameObject(const CGameObject& other)
{
	m_strName	= other.m_strName;
	m_fptPos	= other.m_fptPos;
	m_fptScale	= other.m_fptScale;
	m_bAlive	= true;
	m_pCollider = nullptr;
	m_pAnimator = nullptr;
	if (nullptr != other.m_pCollider)	//복사하는 애가 충돌체가 있으면 충돌체를 새로만들고 넣어줌
	{
		m_pCollider = new CCollider(*other.m_pCollider);
		m_pCollider->m_pOwner = this;
	}
	if (nullptr != other.m_pAnimator)
	{
		m_pAnimator = new CAnimator(*other.m_pAnimator);
		m_pAnimator->m_pOwner = this;
	}
}

CGameObject::~CGameObject()
{
	if (nullptr != m_pCollider)
	{
		delete m_pCollider;
	}
	if (nullptr != m_pAnimator)
	{
		delete m_pAnimator;
	}
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
	fPoint fptRenderPos = CCameraManager::getInst()->GetRenderPos(m_fptPos);
	
	Rectangle(hDc,
		(int)(fptRenderPos.x - GetScale().x / 2),
		(int)(fptRenderPos.y - GetScale().y / 2),
		(int)(fptRenderPos.x + GetScale().x / 2),
		(int)(fptRenderPos.y + GetScale().y / 2));
	
	component_render(hDc);
}

void CGameObject::component_render(HDC hDc)
{
	if (nullptr != m_pAnimator)
	{
		m_pAnimator->Render(hDc);
	}
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

CAnimator* CGameObject::GetAnimator()
{
	return m_pAnimator;
}

void CGameObject::CreateAnimator()
{
	m_pAnimator = new CAnimator();
	m_pAnimator->m_pOwner = this;
}

bool CGameObject::isDead()
{
	return !m_bAlive;
}

void CGameObject::SetDead()
{
	m_bAlive = false;
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
