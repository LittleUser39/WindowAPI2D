#pragma once

class CGameObject;

struct tEvent
{
	TYPE_EVENT eEvent; //�̺�Ʈ Ÿ��
	DWORD_PTR	   lparam;	//�߰����� ����
	DWORD_PTR	   wparam;	//�߰����� ����
};

class CEventManager
{
	SINGLETON(CEventManager);

private:
	vector<tEvent> m_vecEvent;		//���� �̺�Ʈ�� ���� ����
	vector<CGameObject*> m_vecDead; //���� ������ ������Ʈ�� ������ - ���� �����ӿ� ����

	void Execute(const tEvent& event);

public:
	void Update();

	void AddEvent(const tEvent& event); //�̺�Ʈ �Ŵ����� ��⿭�� �̺�Ʈ �߰�
	void EventCreateObject(CGameObject* pObj,GROUP_GAMEOBJ group); //������Ʈ ����
	void EventDeleteObject(CGameObject* pObj);					   //������Ʈ ����

};

