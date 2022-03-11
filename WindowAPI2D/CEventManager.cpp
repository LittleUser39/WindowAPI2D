#include "framework.h"
#include "CEventManager.h"
#include "CGameObject.h"
#include "CScene.h"

CEventManager::CEventManager()
{

}
CEventManager::~CEventManager()
{

}

void CEventManager::Execute(const tEvent& event)
{
	switch (event.eEvent)
	{
	case TYPE_EVENT::CREATE_OBJECT:
	{
		//creat object
		//iparam object주소
		//wparam group 주소
		CGameObject* pObj = (CGameObject*)event.lparam;
		GROUP_GAMEOBJ group = (GROUP_GAMEOBJ)event.wparam;

		CSceneManager::getInst()->GetCurScene()->AddObject(pObj, group);
	}
		break;
	case TYPE_EVENT::DELETE_OBJECT:
	{
		//delete object
		//lparma 주소
		//죽을 예정인 오브젝트 관리
		//여기서 삭제는 아니고 설정과 지울 백터에 넣어줌
		CGameObject* pObj = (CGameObject*)event.lparam;
		if(pObj->isDead()) //이거 없어서 미사일 오류남
			break;
		pObj->SetDead();
		m_vecDead.push_back(pObj);
	}
		break;
	case TYPE_EVENT::CHANGE_SCENE:
		//change scene
		//lparam : scene 그룹
		GROUP_SCENE scene = (GROUP_SCENE)event.lparam;
		CUIManager::getInst()->SetFocusedUI(nullptr);
		CSceneManager::getInst()->ChangeScene(scene);
		break;
	}
}

void CEventManager::Update()
{	
	//여기서 죽은 오브젝트 삭제
	//먼저 삭제후 이벤트 실행해야하여 위에 배치
	for (int i = 0; i < m_vecDead.size(); i++)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();

	//이벤트 실행
	for (int i = 0; i < m_vecEvent.size(); i++)
	{
		Execute(m_vecEvent[i]);
	}
	m_vecEvent.clear();
}

void CEventManager::AddEvent(const tEvent& event)
{
	m_vecEvent.push_back(event);
}

void CEventManager::EventCreateObject(CGameObject* pObj, GROUP_GAMEOBJ group)
{
	tEvent event = {};
	event.eEvent = TYPE_EVENT::CREATE_OBJECT;
	event.lparam = (DWORD_PTR)pObj;
	event.wparam = (DWORD_PTR)group;

	AddEvent(event);
}

void CEventManager::EventDeleteObject(CGameObject* pObj)
{
	tEvent event = {};
	event.eEvent = TYPE_EVENT::DELETE_OBJECT;
	event.lparam = (DWORD_PTR)pObj;
	AddEvent(event);
}

void CEventManager::EventChangeScene(GROUP_SCENE scene)
{
	tEvent event = {};
	event.eEvent = TYPE_EVENT::CHANGE_SCENE;
	event.lparam = (DWORD_PTR)scene;
	AddEvent(event);
}
