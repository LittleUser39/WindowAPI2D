#include "framework.h"
#include "CScene_Tool.h"
#include "CTile.h"
#include "resource.h"
#include "CScene.h"
#include "CTexture.h"
#include "commdlg.h"
#include "CUI.h"	
#include "CPanelUI.h"
#include "CButtonUI.h"

INT_PTR CALLBACK TileWinProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

CScene_Tool::CScene_Tool()
{
	m_hWnd = 0;
	m_Idx = 0;	
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
	if (KEY('A'))
	{
		CCameraManager::getInst()->Scroll(fVec2(-1, 0), m_fVelocity);
	}
	if (KEY('D'))
	{
		CCameraManager::getInst()->Scroll(fVec2(1, 0), m_fVelocity);
	}
	if (KEY('W'))
	{
		CCameraManager::getInst()->Scroll(fVec2(0, -1), m_fVelocity);
	}
	if (KEY('S'))
	{
		CCameraManager::getInst()->Scroll(fVec2(0, 1), m_fVelocity);
	}

	SetTileIdx();
}
void test(DWORD_PTR param1, DWORD_PTR param2)
{
	int a = 0;
}

void CScene_Tool::Enter()
{
	CCameraManager::getInst()->SetLookAt(fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f));

	m_hWnd = CreateDialog(hInst, MAKEINTRESOURCE(IDD_TILEBOX), hWnd, TileWinProc); //�������
	ShowWindow(m_hWnd, SW_SHOW);

	// UI ����
	CPanelUI* pPanelUI = new CPanelUI();
	pPanelUI->SetScale(fPoint(200.f, 80.f));
	pPanelUI->SetPos(fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f));		// UI�� ī�޶��� ��ġ�� ������� ���� ��ǥ�� ���� ����
	AddObject(pPanelUI, GROUP_GAMEOBJ::UI);

	CButtonUI* pButtonUI = new CButtonUI();
	pButtonUI->SetScale(fPoint(100.f, 40.f));
	pButtonUI->SetPos(fPoint(10.f, 10.f));
	pButtonUI->SetClickCallBack(test, 0, 0);
	pPanelUI->AddChild(pButtonUI);
}


void CScene_Tool::Exit()
{
	EndDialog(m_hWnd, IDOK);
	DeleteGroup(GROUP_GAMEOBJ::TILE);
}

void CScene_Tool::SetIdx(UINT idx)
{
	m_Idx = idx;
}

void CScene_Tool::SetTileIdx()
{
	if (KEY(VK_LBUTTON))
	{
		fPoint fptMousePos = MousePos();
		fptMousePos = CCameraManager::getInst()->GetRealPos(fptMousePos);

		//���õ� Ÿ���� m_idx = tool m_idx
		int iTileX = (int)GetTileX();
		int iTileY = (int)GetTileY();

		int iX = (int)fptMousePos.x / CTile::SIZE_TILE;
		int iY = (int)fptMousePos.y / CTile::SIZE_TILE;

		if (fptMousePos.x < 0.f || iTileX <= iX ||
			fptMousePos.y < 0.f || iTileY <= iY)
		{
			return; //Ÿ�� �� ��ġ Ŭ���� �׳� ��ȯ
		}

		UINT iIdx = iTileX * iY + iX;
		const vector<CGameObject*>& vecTile = GetGroupObject(GROUP_GAMEOBJ::TILE);
		((CTile*)vecTile[iIdx])->SetTileIdx(m_Idx);
	}
}

void CScene_Tool::SaveTile(const wstring& strPath)
{
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, strPath.c_str(), L"wb");		// w : write, b : binary
	assert(pFile);

	UINT xCount = GetTileX();
	UINT yCount = GetTileY();

	fwrite(&xCount, sizeof(UINT), 1, pFile);
	fwrite(&yCount, sizeof(UINT), 1, pFile);

	const vector<CGameObject*>& vecTile = GetGroupObject(GROUP_GAMEOBJ::TILE);

	for (UINT i = 0; i < vecTile.size(); i++)
	{
		((CTile*)vecTile[i])->Save(pFile);
	}

	fclose(pFile);
}

void CScene_Tool::SaveTileDate()
{
	OPENFILENAME ofn = {};

	ofn.lStructSize = sizeof(OPENFILENAME);				// ����ü ������.
	ofn.hwndOwner = hWnd;								// �θ� ������ ����.
	wchar_t szName[256] = {};
	ofn.lpstrFile = szName;								// ���߿� �ϼ��� ��ΰ� ä���� ���� ����.
	ofn.nMaxFile = sizeof(szName);						// lpstrFile�� ������ ������ ���� ��.
	ofn.lpstrFilter = L"ALL\0*.*\0tile\0*.tile";		// ���� ����
	ofn.nFilterIndex = 0;								// �⺻ ���� ����. 0�� all�� �ʱ� ���õ�. ó����.
	ofn.lpstrFileTitle = nullptr;						// Ÿ��Ʋ ��
	ofn.nMaxFileTitle = 0;								// Ÿ��Ʋ �� ���ڿ� ũ��. nullptr�̸� 0.
	wstring strTileFolder = CPathManager::getInst()->GetContentPath();
	strTileFolder += L"tile";
	ofn.lpstrInitialDir = strTileFolder.c_str();		 // �ʱ���. �츮�� Ÿ�� �����Ұű� ������, content->tile ��η� �ص���.
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;	 // ��Ÿ��

	if (GetSaveFileName(&ofn))
	{
		SaveTile(szName);
	}
}

void CScene_Tool::LoadTileDate()
{
	OPENFILENAME ofn = {};

	ofn.lStructSize = sizeof(OPENFILENAME);  // ����ü ������.
	ofn.hwndOwner = hWnd; // �θ� ������ ����.
	wchar_t szName[256] = {};
	ofn.lpstrFile = szName; // ���߿� �ϼ��� ��ΰ� ä���� ���� ����.
	ofn.nMaxFile = sizeof(szName); // lpstrFile�� ������ ������ ���� ��.
	ofn.lpstrFilter = L"ALL\0*.*\0tile\0*.tile"; // ���� ����
	ofn.nFilterIndex = 0; // �⺻ ���� ����. 0�� all�� �ʱ� ���õ�. ó����.
	ofn.lpstrFileTitle = nullptr; // Ÿ��Ʋ ��
	ofn.nMaxFileTitle = 0; // Ÿ��Ʋ �� ���ڿ� ũ��. nullptr�̸� 0.
	wstring strTileFolder = CPathManager::getInst()->GetContentPath();
	strTileFolder += L"tile";
	ofn.lpstrInitialDir = strTileFolder.c_str(); // �ʱ���. �츮�� Ÿ�� �����Ұű� ������, content->tile ��η� �ص���.
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; // ��Ÿ��

	if (GetOpenFileName(&ofn))
	{
		LoadTile(szName);
	}
}



// Ÿ�� ���̾�α� �ڽ��� �޼��� ó�����Դϴ�.
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
			//�����ϱ�
			CScene* pCurScen = CSceneManager::getInst()->GetCurScene();

			CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScen); //<>�ȿ� �ִ� ���� ��ȯ�� �����ϴ� ��ȯ, �Ұ��� �׳� nullptr�� �ִ� �Լ�
			assert(pToolScene);
			
			pToolScene->SaveTileDate();

			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCLOAD)
		{
			//todo �ҷ�����
			CScene* pCurScen = CSceneManager::getInst()->GetCurScene();

			CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScen); //<>�ȿ� �ִ� ���� ��ȯ�� �����ϴ� ��ȯ, �Ұ��� �׳� nullptr�� �ִ� �Լ�
			assert(pToolScene);

			pToolScene->LoadTileDate();

			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDOK2)
		{
			//todo �Է��� ũ��δٰ� Ÿ�� ������ ����
			int x = GetDlgItemInt(hDlg, IDC_EDIT1, nullptr, false);
			int y = GetDlgItemInt(hDlg, IDC_EDIT2, nullptr, false);

			CScene* pCurScen = CSceneManager::getInst()->GetCurScene();

			CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScen); //<>�ȿ� �ִ� ���� ��ȯ�� �����ϴ� ��ȯ, �Ұ��� �׳� nullptr�� �ִ� �Լ�
			assert(pToolScene);

				pToolScene->DeleteGroup(GROUP_GAMEOBJ::TILE);
				pToolScene->CreateTile(x, y);
		}
		else if (LOWORD(wParam) == IDOK3)
		{
			int index = GetDlgItemInt(hDlg, IDC_EDIT3, nullptr, false);
			
			CScene* pCurScen = CSceneManager::getInst()->GetCurScene();

			CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScen); //<>�ȿ� �ִ� ���� ��ȯ�� �����ϴ� ��ȯ, �Ұ��� �׳� nullptr�� �ִ� �Լ�
			assert(pToolScene);

			CTexture* pTex = CResourceManager::getInst()->LoadTexture(L"Tile", L"\\texture\\Tile\\tilemap.bmp");

			UINT iWidth = pTex->GetBmpWidth();
			UINT iHeight = pTex->GetBmpHeight();

			UINT iMaxRow = iHeight / CTile::SIZE_TILE;
			UINT iMaxCol = iWidth / CTile::SIZE_TILE;

			UINT iCurRow = (index / iMaxCol) % iMaxRow;
			UINT iCurCol = (index % iMaxCol);

			// �ӽ÷� �̹��� ���
			BitBlt(GetDC(hDlg),
				(int)(150),
				(int)(150),
				(int)(CTile::SIZE_TILE),
				(int)(CTile::SIZE_TILE),
				pTex->GetDC(),
				(int)(iCurCol * CTile::SIZE_TILE),
				(int)(iCurRow * CTile::SIZE_TILE),
				SRCCOPY);
			pToolScene->SetIdx(index);
		}
		break;
	}
	return (INT_PTR)FALSE;
}
