#include "framework.h"
#include "CScene_Tool.h"
#include "CTile.h"
#include "resource.h"

INT_PTR CALLBACK TileWinProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

CScene_Tool::CScene_Tool()
{
	m_hWnd = 0;
	
}

CScene_Tool::~CScene_Tool()
{
}

void CScene_Tool::Update()
{
	CScene::Update();
	if (KEYDOWN(VK_SPACE))
	{
		ChangeScn(GROUP_SCENE::START);
	}
	
}

void CScene_Tool::Enter()
{
	CTexture* pTileTex = CResourceManager::getInst()->LoadTexture(L"Tile", L"\\texture\\Tile\\tilemap.bmp");
	//Tile생성
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			CTile* pTile = new CTile();
			pTile->SetPos(fPoint((float)(j * CTile::SIZE_TILE), (float)(i * CTile::SIZE_TILE)));
			pTile->SetTexture(pTileTex);
			AddObject(pTile, GROUP_GAMEOBJ::TILE);
		}
	}
	
	CCameraManager::getInst()->SetLookAt(fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f));

	m_hWnd = CreateDialog(hInst, MAKEINTRESOURCE(IDD_TILEBOX), hWnd, TileWinProc); //모랄리스
	ShowWindow(m_hWnd, SW_SHOW);
}

void CScene_Tool::Exit()
{
	EndDialog(m_hWnd, IDOK);
}

// 타일 다이얼로그 박스의 메세지 처리기입니다.
INT_PTR CALLBACK TileWinProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			//todo 저장하기
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			//todo 불러오기
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
