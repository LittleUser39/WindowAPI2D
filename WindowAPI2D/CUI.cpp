#include "framework.h"
#include "CUI.h"
#include "SelectGDI.h"
#include "CGameObject.h"

CUI::CUI()
{
	m_pParentUI = nullptr;
	m_bCameraAffected = false;
	m_bLbtnDown = false;
	m_bMouseOn = false;

}

CUI::CUI(const CUI& other) :CGameObject(other)	//부모의 복사생성자를 지목
{
	m_pParentUI = nullptr;
	m_bLbtnDown = false;
	m_bMouseOn = false;
	m_bCameraAffected = other.m_bCameraAffected;
	
	m_vecChildUI.clear();
	
	for (UINT i = 0; i < other.m_vecChildUI.size(); i++)
	{
		AddChild(other.m_vecChildUI[i]->Clone());
	}
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

	MouseOnCheck();

	finalUpdate_Child();
}

void CUI::Render(HDC hDc)
{
	fPoint fptPos = GetFinalPos();
	fPoint fptScale = GetScale();

	if (m_bCameraAffected)//카메라 영향을 받으면 렌더링 좌표를 카메라 기준으로 해줘서 그림
	{
		fptPos = CCameraManager::getInst()->GetRenderPos(fptPos);
	}
	if (m_bLbtnDown)
	{
		SelectGDI green(hDc, TYPE_PEN::GREEN);

		Rectangle(hDc,
			(int)(fptPos.x),
			(int)(fptPos.y),
			(int)(fptPos.x + fptScale.x),
			(int)(fptPos.y + fptScale.y));
	}
	else
	{
		Rectangle(hDc,
			(int)(fptPos.x),
			(int)(fptPos.y),
			(int)(fptPos.x + fptScale.x),
			(int)(fptPos.y + fptScale.y));

	}
	
	Render_Child(hDc);
}

CUI* CUI::Clone()
{
	return new CUI(*this);
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
	int a = 0;
}

void CUI::MouseLbtnDown()
{
	int a = 0;
}

void CUI::MouseLbtnUp()
{
	int a = 0;
}

void CUI::MouseLbtnClick()
{
	int a = 0;
}

void CUI::SetCameraAffected(bool affected)
{
	m_bCameraAffected = affected;
	for (UINT i = 0; i < m_vecChildUI.size();i++)
	{
		m_vecChildUI[i]->SetCameraAffected(affected);
	}
}

fPoint CUI::GetFinalPos()
{
	return m_fptFinalPos;
}

CUI* CUI::GetParent()
{
	return m_pParentUI;
}

const vector<CUI*> CUI::GetChildUI()
{
	return m_vecChildUI;
}

bool CUI::GetCameraAffected()
{
	return m_bCameraAffected;
}

void CUI::AddChild(CUI* pUI)
{
	m_vecChildUI.push_back(pUI);
	pUI->m_pParentUI = this;
}

bool CUI::IsMouseON()
{
	return m_bMouseOn;
}

bool CUI::IsLbtnDown()
{
	return m_bLbtnDown;
}

void CUI::MouseOnCheck()
{
	fPoint fptMousePos = MousePos();
	fPoint fptScale = GetScale();

	if (m_bCameraAffected)
	{
		fptMousePos = CCameraManager::getInst()->GetRealPos(fptMousePos);
	}
	if (m_fptFinalPos.x <= fptMousePos.x && fptMousePos.x <= m_fptFinalPos.x + fptScale.x 
		&& m_fptFinalPos.y <= fptMousePos.y && fptMousePos.y <= m_fptFinalPos.y + fptScale.y)
	{
		m_bMouseOn = true;
	}
	else
	{
		m_bMouseOn = false;
	}
}
