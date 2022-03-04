#include "framework.h"
#include "CCore.h"



CCore::CCore()
{
	m_hDC = 0;
	m_hBMP = 0;
	m_hMemDC = 0;
	m_arrPen[0] = 0;
	m_arrBrush[0] = 0;
}

CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);

	for (int i = 0; i < (int)TYPE_PEN::SIZE; i++)
	{
		DeleteObject (m_arrPen[i]);
	}
}



void CCore::update()
{
	CEventManager::getInst()->Update();

	CTimeManager::getInst()->update();
	CKeyManager::getInst()->Update(); //���⼭ Ű�� �޾Ƽ� ��Ȯ�� ���� �ð��� Ű�� �޾� ������
	CSceneManager::getInst()->Update();
	CCollisionManager::getInst()->Update();
	CCameraManager::getInst()->Update();
	
}

void CCore::render()
{
	//������ ������ ���� �׷��ִ� �۾�

	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	CSceneManager::getInst()->Render(m_hMemDC);

	// ������ ��ܿ� FPS ǥ��
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);

	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}

void CCore::init()
{
	//core�� �ʱ�ȭ ����
	CPathManager::getInst()->init(); //���� - �̹����� �ҷ��ͼ� ������ ����ؾ���
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->Init();
	CSceneManager::getInst()->Init();
	CCollisionManager::getInst()->init();

	createBrushPen();

	m_hDC = GetDC(hWnd);

	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap =(HBITMAP) SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

}

HDC CCore::GetMainDC()	
{
	return m_hMemDC; //�޸� dc�� �׷����� 
}

void CCore::createBrushPen()
{
	//brush
	m_arrBrush[(int)TYPE_BRUSH::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	//pen
	m_arrPen[(int)TYPE_PEN::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(int)TYPE_PEN::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(int)TYPE_PEN::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

}

HPEN CCore::GetPen(TYPE_PEN pen)
{
	return m_arrPen[(int)pen];
}

HBRUSH CCore::GetBrush(TYPE_BRUSH brush)
{
	return m_arrBrush[(int)brush];
}
