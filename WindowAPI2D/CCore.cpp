#include "framework.h"
#include "CCore.h"

CGameObject object;

CCore::CCore()
{
	m_hDC = 0;
	m_hBMP = 0;
	m_hMemDC = 0;
}

CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);

}

fPoint g_rectPos;

void CCore::update()
{
	
	CTimeManager::getInst()->update();

	fPoint pos = object.GetPos();
	// GetAsuncKeyState : 메시지 큐에 키 입력을 받는 방식이 아닌 현재 상태의 키 입력상태를 확인
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		pos.x -= 100 * CTimeManager::getInst()->GetDT();
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		pos.x += 100 * CTimeManager::getInst()->GetDT();
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		pos.y -= 100 * CTimeManager::getInst()->GetDT();
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		pos.y += 100 * CTimeManager::getInst()->GetDT();
	}

	object.SetPos(pos);
}

void CCore::render()
{
	//게임의 정보를 토대로 그려주는 작업

	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale().y / 2,
		object.GetPos().x + object.GetScale().x / 2,
		object.GetPos().y + object.GetScale().y / 2);

	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2 + 200,
		object.GetPos().y - object.GetScale().y / 2,
		object.GetPos().x + object.GetScale().x / 2 + 200,
		object.GetPos().y + object.GetScale().y / 2);

	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale().y / 2 + 200,
		object.GetPos().x + object.GetScale().x / 2,
		object.GetPos().y + object.GetScale().y / 2 + 200);

	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2 + 200,
		object.GetPos().y - object.GetScale().y / 2 + 200,
		object.GetPos().x + object.GetScale().x / 2 + 200,
		object.GetPos().y + object.GetScale().y / 2 + 200);

	// 오른쪽 상단에 FPS 표시
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);

	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}

void CCore::init()
{
	//core의 초기화 과정
	CTimeManager::getInst()->init();

	m_hDC = GetDC(hWnd);

	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap =(HBITMAP) SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	object = CGameObject(fPoint(100, 100), fPoint{ 100, 100 });
}