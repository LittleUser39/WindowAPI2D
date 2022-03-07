#include "framework.h"
#include "CScene.h"
#include "CGameObject.h"
#include "CTile.h"
CScene::CScene()
{
	m_strName = L"";
	m_iTileX = 0;
	m_iTileY = 0;

}

CScene::~CScene()
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			delete m_arrObj[i][j];
		}
	}
}
void CScene::Update()
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			if (!m_arrObj[i][j]->isDead())	//죽지않았으면 업데이트
			{
				m_arrObj[i][j]->Update();
			}
		}
	}
}
void CScene::finalUpdate()
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->finalUpdate();
		}
	}
}

void CScene::Render(HDC hDc)
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (vector<CGameObject*>::iterator iter = m_arrObj[i].begin(); 
			iter != m_arrObj[i].end();)
		{
			if(!(*iter)->isDead())	//죽지않은 오브젝트면 그려주고 아니면 삭제
			{
				(*iter)->Render(hDc);
				iter++;
			}
			else
			{
				iter = m_arrObj[i].erase(iter);
			}
		}
	}
}


const vector<CGameObject*>& CScene::GetGroupObject(GROUP_GAMEOBJ group)
{
	return m_arrObj[(UINT)group];}

void CScene::SetName(const wstring& strName)
{
	m_strName = strName;
}

wstring CScene::GetName()
{
	return m_strName;
}

UINT CScene::GetTileX()
{
	return m_iTileX;
}

UINT CScene::GetTileY()
{
	return m_iTileY;
}

void CScene::AddObject(CGameObject* pObj, GROUP_GAMEOBJ type)
{
	m_arrObj[(int)type].push_back(pObj);
}

void CScene::DeleteGroup(GROUP_GAMEOBJ group)
{
	for (int i = 0; i < m_arrObj[(UINT)group].size(); i++)
	{
		delete m_arrObj[(UINT)group][i];
	}
	m_arrObj[(UINT)group].clear();
}

void CScene::DeleteAll()
{
	for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	{
		DeleteGroup((GROUP_GAMEOBJ)i);
	}
}

void CScene::CreateTile(UINT xsize, UINT ysize)
{
	DeleteGroup(GROUP_GAMEOBJ::TILE);

	m_iTileX = xsize;
	m_iTileY = ysize;
	
	CTexture* pTileTex = CResourceManager::getInst()->LoadTexture(L"Tile", L"\\texture\\Tile\\tilemap.bmp");
	//Tile생성
	for (int i = 0; i < ysize; i++)
	{
		for (int j = 0; j < xsize; j++)
		{
			CTile* pTile = new CTile();
			pTile->SetPos(fPoint((float)(j * CTile::SIZE_TILE), (float)(i * CTile::SIZE_TILE)));
			pTile->SetTexture(pTileTex);
			AddObject(pTile, GROUP_GAMEOBJ::TILE);
		}
	}
}

void CScene::LoadTile(const wstring& strPath)
{
	wstring strFillPath = CPathManager::getInst()->GetContentPath();
	strFillPath += strPath;

	FILE* pFile = nullptr;

	_wfopen_s(&pFile, strFillPath.c_str(), L"rb");
	assert(pFile);

	UINT xCount = 0;
	UINT yCount = 0;

	fread(&xCount, sizeof(UINT), 1, pFile);
	fread(&yCount, sizeof(UINT), 1, pFile);
	
	const vector<CGameObject*> vecTile = GetGroupObject(GROUP_GAMEOBJ::TILE);

	for (UINT i = 0; i < vecTile.size(); i++)
	{
		((CTile*)vecTile[i])->Load(pFile);
	}

	fclose(pFile);
}

