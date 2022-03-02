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
	vector<CGameObject*> m_vecDead; //죽을 예정인 오브젝트를 넣은후 - 다음 프레임에 삭제

	void Execute(const tEvent& event);

public:
	void Update();

	void AddEvent(const tEvent& event); //이벤트 매니저의 대기열에 이벤트 추가
	void EventCreateObject(CGameObject* pObj,GROUP_GAMEOBJ group); //오브젝트 생성
	void EventDeleteObject(CGameObject* pObj);					   //오브젝트 제거
};

