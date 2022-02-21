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
	CKeyManager::getInst()->Update(); //���⼭ Ű�� �޾Ƽ� ��Ȯ�� ���� �ð��� Ű�� �޾� ������

	fPoint pos = object.GetPos();
	// GetAsuncKeyState : �޽��� ť�� Ű �Է��� �޴� ����� �ƴ� ���� ������ Ű �Է»��¸� Ȯ��
	if (KEY(VK_LEFT))
	{
		pos.x -= 100 * DT;
	}
	if (KEY(VK_RIGHT))
	{
		pos.x += 100 * DT;
	}
	if (KEY(VK_UP))
	{
		pos.y -= 100 * DT;
	}
	if (KEY(VK_DOWN))
	{
		pos.y += 100 * DT;
	}

	object.SetPos(pos);
}

void CCore::render()
{
	//������ ������ ���� �׷��ִ� �۾�

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

	// ������ ��ܿ� FPS ǥ��
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);

	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}

void CCore::init()
{
	//core�� �ʱ�ȭ ����
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->Init();
	

	m_hDC = GetDC(hWnd);

	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap =(HBITMAP) SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	object = CGameObject(fPoint(100, 100), fPoint{ 100, 100 });
}