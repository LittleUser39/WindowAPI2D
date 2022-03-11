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
	CKeyManager::getInst()->Update(); //여기서 키를 받아서 정확히 누른 시간에 키를 받아 움직임
	CSoundManager::getInst()->Update();
	CSceneManager::getInst()->Update();
	CCollisionManager::getInst()->Update();
	CCameraManager::getInst()->Update();
	CUIManager::getInst()->Update();
}

void CCore::render()
{
	//게임의 정보를 토대로 그려주는 작업

	Rectangle(m_pMemTex->GetDC(), -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	CSceneManager::getInst()->Render(m_pMemTex->GetDC());
	CCameraManager::getInst()->Render(m_pMemTex->GetDC());

	// 오른쪽 상단에 FPS 표시
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_pMemTex->GetDC(), WINSIZEX - 50, 10, strFPS, 5);

	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_pMemTex->GetDC(), 0, 0, SRCCOPY);
}

void CCore::init()
{
	createBrushPen();
	m_hDC = GetDC(hWnd);
	//core의 초기화 과정
	CPathManager::getInst()->init(); //순서 - 이미지를 불러와서 씬에서 사용해야함
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
	return m_hDC; //메모리 dc에 그려야함 
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
