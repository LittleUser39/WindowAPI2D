#pragma once

class CGameObject;

struct tEvent
{
	TYPE_EVENT eEvent; //이벤트 타입
	DWORD	   lparam;	//추가적인 정보
	DWORD	   wparam;	//추가적인 정보
};

class CEventManager
{
	SINGLETON(CEventManager);

private:
	vector<tEvent> m_vecEvent;

	void Execute(const tEvent& event);

public:
	void Update();

	void AddEvent(const tEvent& event); //이벤트 매니저의 대기열에 이벤트 추가
	void EventCreateObject(CGameObject* pObj,GROUP_GAMEOBJ group); //게임오브젝트 생성
};

