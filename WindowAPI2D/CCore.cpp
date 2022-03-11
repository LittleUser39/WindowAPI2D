#include "framework.h"
#include "CCore.h"
#include "CTexture.h"


CCore::CCore()
{
	m_hDC = 0;

	m_arrPen[0] = 0;
	m_arrBrush[0] = 0;
}

CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);


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
	CSoundManager::getInst()->Update();
	CSceneManager::getInst()->Update();
	CCollisionManager::getInst()->Update();
	CCameraManager::getInst()->Update();
	CUIManager::getInst()->Update();
}

void CCore::render()
{
	//������ ������ ���� �׷��ִ� �۾�

	Rectangle(m_pMemTex->GetDC(), -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	CSceneManager::getInst()->Render(m_pMemTex->GetDC());
	CCameraManager::getInst()->Render(m_pMemTex->GetDC());

	// ������ ��ܿ� FPS ǥ��
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_pMemTex->GetDC(), WINSIZEX - 50, 10, strFPS, 5);

	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_pMemTex->GetDC(), 0, 0, SRCCOPY);
}

void CCore::init()
{
	createBrushPen();
	m_hDC = GetDC(hWnd);
	//core�� �ʱ�ȭ ����
	CPathManager::getInst()->init(); //���� - �̹����� �ҷ��ͼ� ������ ����ؾ���
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->Init();
	CSoundManager::getInst()->init();
	CSceneManager::getInst()->Init();
	CCollisionManager::getInst()->init();
	CCameraManager::getInst()->init();

	m_pMemTex = CResourceManager::getInst()->CreateTexture(L"CoreTex",WINSIZEX,WINSIZEY);
}

HDC CCore::GetMainDC()	
{
	return m_hDC; //�޸� dc�� �׷����� 
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
