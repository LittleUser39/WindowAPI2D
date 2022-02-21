#include "framework.h"
#include "CScene.h"

CScene::CScene()
{
	m_strName = L"";
}

CScene::~CScene()
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			delete m_arrObj[i][j];
		}
	}
}
void CScene::Update()
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->Update();
		}
	}
}

void CScene::Render(HDC hDc)
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->Render(hDc);
		}
	}
}

void CScene::SetName(const wstring& strName)
{
	m_strName = strName;
}

wstring CScene::GetName()
{
	return m_strName;
}

void CScene::AddObject(CGameObject* pObj, GROUP_GAMEOBJ Obj)
{
	m_arrObj[(int)Obj].push_back(pObj);
}
