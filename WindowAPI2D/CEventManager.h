#pragma once

class CGameObject;

struct tEvent
{
	TYPE_EVENT eEvent; //�̺�Ʈ Ÿ��
	DWORD	   lparam;	//�߰����� ����
	DWORD	   wparam;	//�߰����� ����
};

class CEventManager
{
	SINGLETON(CEventManager);

private:
	vector<tEvent> m_vecEvent;

	void Execute(const tEvent& event);

public:
	void Update();

	void AddEvent(const tEvent& event); //�̺�Ʈ �Ŵ����� ��⿭�� �̺�Ʈ �߰�
	void EventCreateObject(CGameObject* pObj,GROUP_GAMEOBJ group); //���ӿ�����Ʈ ����
};

