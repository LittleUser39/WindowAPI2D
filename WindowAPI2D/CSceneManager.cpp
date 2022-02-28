#include "framework.h"
#include "CSceneManager.h"
#include "CScene_Start.h"
#include "CScene_STAGE_01.h"
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
	//���� ����� �ڽ��̸� �׳� ����
	if (m_arrScene[(int)type] == m_pCurScene)
		return;
	//���� ����� ������ ��������� ���� ������� ������ ������鿡 ��
	m_pCurScene->Exit();
	m_pCurScene = m_arrScene[(int)type];
	m_pCurScene->Enter();
	//�庯 ����
}

void CSceneManager::Init()
{
	//todo : ����� �߰�
	m_arrScene[(int)GROUP_SCENE::START] = new CScene_Start;
	m_arrScene[(int)GROUP_SCENE::START]->SetName(L"START_SCENE");

	//�ϴ� �������� 01 �߰��غ�
	m_arrScene[(int)GROUP_SCENE::STAGE_01] = new CScene_STAGE_01;
	m_arrScene[(int)GROUP_SCENE::STAGE_01]->SetName(L"STAGE_01");

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
	m_pCurScene->finalUpdate();

	if (KEYDOWN(VK_SPACE))
	{
		ChangeScene(GROUP_SCENE::STAGE_01);
	}
	if (KEYDOWN(VK_BACK))
	{
		ChangeScene(GROUP_SCENE::START);
	}
	m_pCurScene->Update();
}

CScene* CSceneManager::GetCurScene()
{
	return m_pCurScene;
}
