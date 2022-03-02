#include "framework.h"
#include "CEventManager.h"
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
		//iparam object林家
		//wparam group 林家
		CGameObject* pObj = (CGameObject*)event.lparam;
		GROUP_GAMEOBJ group = (GROUP_GAMEOBJ)event.wparam;

		CSceneManager::getInst()->GetCurScene()->AddObject(pObj, group);
	}
	break;
	case TYPE_EVENT::DELETE_OBJECT:
		//delete object
		break;
	case TYPE_EVENT::CHANGE_SCENE:
		//change scene
		break;
	}
}

void CEventManager::Update()
{
	for (int i = 0; i < m_vecEvent.size(); i++)
	{
		Execute(m_vecEvent[i]);
	}
	m_vecEvent.clear();
}

void CEventManager::AddEvent(const tEvent& event)
{
}

void CEventManager::EventCreateObject(CGameObject* pObj, GROUP_GAMEOBJ group)
{
	tEvent event;
	event.eEvent = TYPE_EVENT::CREATE_OBJECT;
	event.lparam = (DWORD_PTR)pObj;
	event.wparam = (DWORD_PTR)group;
}
