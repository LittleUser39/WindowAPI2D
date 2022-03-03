#pragma once

class CGameObject;

struct tEvent
{
	TYPE_EVENT eEvent; //이벤트 타입
	DWORD_PTR	   lparam;	//추가적인 정보
	DWORD_PTR	   wparam;	//추가적인 정보
};

class CEventManager
{
	SINGLETON(CEventManager);

private:
	vector<tEvent> m_vecEvent;		//실행 이벤트를 넣은 백터
	vector<CGameObject*> m_vecDead; //죽을 예정인 오브젝트를 넣은후 - 다음 프레임에 삭제

	void Execute(const tEvent& event);

public:
	void Update();

	void AddEvent(const tEvent& event);							   //이벤트 매니저의 대기열에 이벤트 추가
	void EventCreateObject(CGameObject* pObj,GROUP_GAMEOBJ group); //오브젝트 생성
	void EventDeleteObject(CGameObject* pObj);					   //오브젝트 제거
	void EventChangeScene(GROUP_SCENE scene);					   //장면 전환 이벤트
};

