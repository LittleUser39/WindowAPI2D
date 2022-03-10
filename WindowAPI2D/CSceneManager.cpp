#include "framework.h"
#include "CSceneManager.h"
#include "CScene_Start.h"
#include "CScene_STAGE_01.h"
#include "CScene_Tool.h"
CSceneManager::CSceneManager()
{
	//모든 장면 처음 초기화
	for (int i = 0; i < (int)GROUP_SCENE::SIZE; i++)
	{
		m_arrScene[i] = nullptr;
	}
	m_pCurScene = nullptr;
}

CSceneManager::~CSceneManager()
{
	//모든 장면을 지워줌
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
	m_pCurScene->Exit();
	m_pCurScene = m_arrScene[(UINT)type];
	m_pCurScene->Enter();
}

void CSceneManager::Init()
{
	//todo : 장면을 추가
	m_arrScene[(int)GROUP_SCENE::START] = new CScene_Start;
	m_arrScene[(int)GROUP_SCENE::START]->SetName(L"START_SCENE");

	//일단 스테이지 01 추가해봄
	m_arrScene[(int)GROUP_SCENE::STAGE_01] = new CScene_STAGE_01;
	m_arrScene[(int)GROUP_SCENE::STAGE_01]->SetName(L"STAGE_01");

	m_arrScene[(int)GROUP_SCENE::TOOL] = new CScene_Tool;
	m_arrScene[(int)GROUP_SCENE::TOOL]->SetName(L"TOOL_SCENE");


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
