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
	//todo: ���� ������Ʈ
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
	//FPS�� ǥ��
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hDC, WINSIZEX - 50, 10, strFPS,5);

}

void CCore::render()
{
	//todo: ���� ǥ��
}

void CCore::init()
{
	//core�� �ʱ�ȭ ����
	CTimeManager::getInst()->init();

	m_hDC = GetDC(hWnd);
}