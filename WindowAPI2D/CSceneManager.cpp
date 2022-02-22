#include "framework.h"
#include "CSceneManager.h"
#include "CScene_Start.h"

CSceneManager::CSceneManager()
{
	//��� ��� ó�� �ʱ�ȭ
	for (int i = 0; i < (int)GROUP_SCENE::SIZE; i++)
	{
		m_arrScene[i] = nullptr;
	}
	m_pCurScene = nullptr;
}

CSceneManager::~CSceneManager()
{
	//��� ����� ������
	for (int i = 0; i < (int)GROUP_SCENE::SIZE; i++)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
	
}

void CSceneManager::ChangeScene(GROUP_SCENE type)
{
	//���� ����� ������ ��������� ���� ������� ������ ������鿡 ��
	
	m_pCurScene->Exit();
	m_pCurScene = m_arrScene[(int)type];
	m_pCurScene->Enter();
}

void CSceneManager::Init()
{
	//todo : ����� �߰�
	m_arrScene[(int)GROUP_SCENE::START] = new CScene_Start;
	m_arrScene[(int)GROUP_SCENE::START]->SetName(L"START_SCENE");

	m_pCurScene = m_arrScene[(int)GROUP_SCENE::START];
	m_pCurScene->Enter();
}

void CSceneManager::Render(HDC hDc)
{
	m_pCurScene->Render(hDc);
}

void CSceneManager::Update()
{
	m_pCurScene->Update();
}
