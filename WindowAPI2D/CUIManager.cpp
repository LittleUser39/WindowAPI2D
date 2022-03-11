#include "framework.h"
#include "CUIManager.h"
#include "CUI.h"
#include "CScene.h"

CUIManager::CUIManager()
{
	m_pFocusedUI = nullptr;
}

CUIManager::~CUIManager()
{

}

void CUIManager::Update()
{
	m_pFocusedUI = GetFocusedUI();
	if (m_pFocusedUI == nullptr)
		return;
	CUI* pUI = GetTargetUI(m_pFocusedUI);

	if (nullptr != pUI)
	{
		pUI->MouseOn();
		if (KEYDOWN(VK_LBUTTON))
		{
			pUI->MouseLbtnDown();
			pUI->m_bLbtnDown = true;
		}
		else if (KEYUP(VK_LBUTTON))
		{
			pUI->MouseLbtnUp();
			if (pUI->m_bLbtnDown)
			{
				pUI->MouseLbtnClick();
			}
			pUI->m_bLbtnDown = false;
		}
	}
}

void CUIManager::SetFocusedUI(CUI* pUI)
{
	m_pFocusedUI = pUI;

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	vector<CGameObject*>& vecUI = pCurScene->GetUIGroup();
	
	vector<CGameObject*>::iterator iter;
	for (iter= vecUI.begin(); iter != vecUI.end(); iter++)
	{
		if (m_pFocusedUI == *iter)
		{
			break;
		}
	}

	if (vecUI.end() == iter)
		return;
	vecUI.erase(iter);
	vecUI.push_back(m_pFocusedUI);
}

CUI* CUIManager::GetTargetUI(CUI* pParentUI)
{
	//³Êºñ ¿ì¼± Å½»ö (Å¥·Î Å½»ö)
	static list<CUI*> queue;
	static vector<CUI*> vecNoneTarget;
	CUI* pTargetUI = nullptr;

	queue.push_back(pParentUI);

	while (!queue.empty())
	{
		CUI* pUI = queue.front();
		queue.pop_front();

		if (pUI->IsMouseON())
		{
			if (nullptr != pTargetUI)
			{
				vecNoneTarget.push_back(pTargetUI);
			}
			pTargetUI = pUI;
		}
		else
		{
			vecNoneTarget.push_back(pUI);
		}

		const vector<CUI*>& vecChild = pUI->GetChildUI();
		for (UINT i = 0; i < vecChild.size(); i++)
		{
			queue.push_back(vecChild[i]);
		}
	}

	if (KEYUP(VK_LBUTTON))
	{
		for (UINT i = 0; i < vecNoneTarget.size(); i++)
		{
			vecNoneTarget[i]->m_bLbtnDown = false;
		}
	}



	return pTargetUI;
}

CUI* CUIManager::GetFocusedUI()
{
	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	vector<CGameObject*>& vecUI = pCurScene->GetUIGroup();
	CUI* pFocusedUI = m_pFocusedUI;

	if (!KEYDOWN(VK_LBUTTON))
	{
		return pFocusedUI;
	}

	vector<CGameObject*>::iterator targetiter = vecUI.end();
	vector<CGameObject*>::iterator iter = vecUI.begin();
	for (; iter != vecUI.end(); iter++)
	{
		if (((CUI*)*iter)->IsMouseON())
		{
			targetiter = iter;
		}
	}

	if (vecUI.end() == targetiter)
	{
		return nullptr;
	}

	pFocusedUI = (CUI*)*targetiter;
	
	vecUI.erase(targetiter);
	vecUI.push_back(pFocusedUI);

	return pFocusedUI;
}
