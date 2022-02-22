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
	// 현재 선택(focus)된 윈도우가 게임 윈도우 인가를 확인
	//getfocus 함수는 현재 내가 선택(바라보는) 윈도우의 주소값을 확인하는 함수 - 이젠 (0)이 나옴
	HWND curWnd = GetFocus();
	//만약 게임 윈도우가 선택된 윈도우가 아닐 경우
	if (hWnd != curWnd)
	{
		//윈도우가 선택된 상태가 아닐경우 키입력은 모두 false로 해줌
		for (int key = 0; key < VKEY_SIZE; key++)
		{
			//현재값을 이전 값으로 저장 - 내가 다시 그 윈도우를 했을때 이전 행동을 반영해야하기 때문에
			m_arrPrevKey[key] = m_arrCurKey[key]; 
			m_arrCurKey[key] = false;
		}
		return;
	}

	//모든 키 사이즈 만큼 반복하면서 그 키의 입력 상태를 확인
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
}

void CKeyManager::Init()
{

}

bool CKeyManager::GetButton(const int key)
{
	
	return (true == m_arrCurKey[key] && true == m_arrPrevKey[key]);		//이전과 현재키가 같이 눌림
}

bool CKeyManager::GetButtonDown(const int key)
{
	return (false == m_arrPrevKey[key] && true == m_arrCurKey[key]);	//이전은 안눌리고 현재는 눌림
}

bool CKeyManager::GetButtonUp(const int key)
{
	return (true == m_arrPrevKey[key] && false == m_arrCurKey[key]);	//이전은 눌렸고 현재는 안눌림
}

