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
	if (nullptr != other.m_pCollider)	//�����ϴ� �ְ� �浹ü�� ������ �浹ü�� ���θ���� �־���
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
	if (nullptr != m_pCollider)	//�浹ü�� �ִ�
	{	
		m_pCollider->finalUpdate();	//�浹
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
