#include "framework.h"
#include "CKeyManager.h"

CKeyManager::CKeyManager()
{
	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = false;
		m_arrCurKey[key] = false;
	}
}

CKeyManager::~CKeyManager()
{
	
}

void CKeyManager::Update()
{
	// ���� ����(focus)�� �����찡 ���� ������ �ΰ��� Ȯ��
	//getfocus �Լ��� ���� ���� ����(�ٶ󺸴�) �������� �ּҰ��� Ȯ���ϴ� �Լ� - ���� (0)�� ����
	HWND curWnd = GetFocus();
	//���� ���� �����찡 ���õ� �����찡 �ƴ� ���
	if (hWnd != curWnd)
	{
		//�����찡 ���õ� ���°� �ƴҰ�� Ű�Է��� ��� false�� ����
		for (int key = 0; key < VKEY_SIZE; key++)
		{
			//���簪�� ���� ������ ���� - ���� �ٽ� �� �����츦 ������ ���� �ൿ�� �ݿ��ؾ��ϱ� ������
			m_arrPrevKey[key] = m_arrCurKey[key]; 
			m_arrCurKey[key] = false;
		}
		return;
	}

	//��� Ű ������ ��ŭ �ݺ��ϸ鼭 �� Ű�� �Է� ���¸� Ȯ��
	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = m_arrCurKey[key];
		if (GetAsyncKeyState(key) & 0x8000)
		{
			m_arrCurKey[key] = true;
		}
		else
		{
			m_arrCurKey[key] = false;
		}
	}

	//���콺 ��ǥ�� ��� ������ ����Ʈ ����
	POINT ptPos = {};
	//�����쿡�� ����� �»�� ���� ���콺�� ��ǥ�� ��ȯ
	GetCursorPos(&ptPos); 
	//����� �»�� ������ ���� ������ ���� ���콺 ��ġ�� ���
	ScreenToClient(hWnd, &ptPos);

	m_fptCurMousePos = fPoint((float)ptPos.x, (float)ptPos.y);
}

void CKeyManager::Init()
{

}

bool CKeyManager::GetButton(const int key)
{
	
	return (true == m_arrCurKey[key] && true == m_arrPrevKey[key]);		//������ ����Ű�� ���� ����
}

bool CKeyManager::GetButtonDown(const int key)
{
	return (false == m_arrPrevKey[key] && true == m_arrCurKey[key]);	//������ �ȴ����� ����� ����
}

bool CKeyManager::GetButtonUp(const int key)
{
	return (true == m_arrPrevKey[key] && false == m_arrCurKey[key]);	//������ ���Ȱ� ����� �ȴ���
}

fPoint CKeyManager::GetMousePos()
{
	return m_fptCurMousePos;
}

