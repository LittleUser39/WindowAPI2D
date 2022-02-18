#include "framework.h"
#include "CCore.h"

CCore::CCore()
{
}

CCore::~CCore()
{
}

fPoint g_rectPos;

void CCore::update()
{
	//todo: 게임 업데이트
	CTimeManager::getInst()->init();

	//Rectangle(m_hDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		g_rectPos.x -= 1 * CTimeManager::getInst()->GetDT();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		g_rectPos.x += 1 * CTimeManager::getInst()->GetDT();
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		g_rectPos.y -= 1 * CTimeManager::getInst()->GetDT();
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		g_rectPos.y += 1 * CTimeManager::getInst()->GetDT();
	}
	//FPS를 표현
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hDC, WINSIZEX - 50, 10, strFPS,5);

}

void CCore::render()
{
	//todo: 게임 표현
}

void CCore::init()
{
	//core의 초기화 과정
	CTimeManager::getInst()->init();

	m_hDC = GetDC(hWnd);
}