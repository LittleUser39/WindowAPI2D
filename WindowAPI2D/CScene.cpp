#include "framework.h"
#include "CScene.h"
#include "CGameObject.h"

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
			if (!m_arrObj[i][j]->isDead())	//�����ʾ����� ������Ʈ
			{
				m_arrObj[i][j]->Update();
			}
		}
	}
}
void CScene::finalUpdate()
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->finalUpdate();
		}
	}
}

void CScene::Render(HDC hDc)
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (vector<CGameObject*>::iterator iter = m_arrObj[i].begin(); 
			iter != m_arrObj[i].end();)
		{
			if(!(*iter)->isDead())	//�������� ������Ʈ�� �׷��ְ� �ƴϸ� ����
			{
				(*iter)->Render(hDc);
				iter++;
			}
			else
			{
				iter = m_arrObj[i].erase(iter);
			}
		}
	}
}


const vector<CGameObject*>& CScene::GetGroupObject(GROUP_GAMEOBJ group)
{
	return m_arrObj[(UINT)group];}

void CScene::SetName(const wstring& strName)
{
	m_strName = strName;
}

wstring CScene::GetName()
{
	return m_strName;
}

void CScene::AddObject(CGameObject* pObj, GROUP_GAMEOBJ type)
{
	m_arrObj[(int)type].push_back(pObj);
}

void CScene::ClearObject()
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			delete m_arrObj[i][m_arrObj->size()-1];
			m_arrObj->pop_back();
		}
	}
}
