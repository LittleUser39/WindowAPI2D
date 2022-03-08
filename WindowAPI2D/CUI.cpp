#include "framework.h"
#include "CUI.h"

CUI::CUI()
{
	m_pParentUI = nullptr;
}

CUI::~CUI()
{
	for (UINT i = 0; i < m_vecChildUI.size(); i++)
	{
		if (nullptr != m_vecChildUI[i])
			delete m_vecChildUI[i];
	}
}

void CUI::Update()
{
	Update_Child();
}

void CUI::finalUpdate()
{
	CGameObject::finalUpdate();

	m_fptFinalPos = GetPos();
	if (GetParent())
	{
		fPoint fptParentPos = GetParent()->GetFinalPos();
		m_fptFinalPos += fptParentPos;
	}

	finalUpdate_Child();
}

void CUI::Render(HDC hDc)
{
	fPoint fptPos = GetPos();
	fPoint fptScale = GetScale();

	Rectangle(hDc,
		(int)(m_fptFinalPos.x),
		(int)(m_fptFinalPos.y),
		(int)(m_fptFinalPos.x + fptScale.x),
		(int)(m_fptFinalPos.y + fptScale.y));
	
	Render_Child(hDc);
}

CUI* CUI::Clone()
{
	CUI* newUI = new CUI(*this);
	
	newUI->m_vecChildUI.clear();

	for (UINT i = 0; i < m_vecChildUI.size(); i++)
	{
		newUI->m_vecChildUI.push_back(new CUI(*m_vecChildUI[i]));
		newUI->m_vecChildUI[i]->m_pParentUI = newUI;
	}
	
	return newUI;
}

void CUI::Update_Child()
{
	for (UINT i = 0; i < m_vecChildUI.size(); i++)
	{
		m_vecChildUI[i]->Update();
	}
}

void CUI::Render_Child(HDC hDc)
{
	for (UINT i = 0; i < m_vecChildUI.size(); i++)
	{
		m_vecChildUI[i]->Render(hDc);
	}
}

void CUI::finalUpdate_Child()
{
	for (UINT i = 0; i < m_vecChildUI.size(); i++)
	{
		m_vecChildUI[i]->finalUpdate();
	}
}

void CUI::MouseOn()
{
}

void CUI::MouseLbtnDown()
{
}

void CUI::MouseLbtnUp()
{
}

void CUI::MouseLbtnClick()
{
}

fPoint CUI::GetFinalPos()
{
	return m_fptFinalPos;
}

CUI* CUI::GetParent()
{
	return m_pParentUI;
}

void CUI::AddChild(CUI* pUI)
{
	m_vecChildUI.push_back(pUI);
	pUI->m_pParentUI = this;
}
