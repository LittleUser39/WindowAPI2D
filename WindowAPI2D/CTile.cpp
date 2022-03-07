#include "framework.h"
#include "CTile.h"
#include "CTexture.h"
CTile::CTile()
{
	SetScale(fPoint(SIZE_TILE, SIZE_TILE));
	m_pTex = nullptr;
	m_iIdx = 0;
}

CTile::~CTile()
{
}

CTile* CTile::Clone()
{
	return new CTile(*this);
}

void CTile::Update()
{
}

void CTile::Render(HDC hDc)
{
	if (nullptr == m_pTex)
	{
		return;
	}
	UINT iWidth = m_pTex->GetBmpWidth();
	UINT iHeight = m_pTex->GetBmpHeight();

	UINT iMaxX = iWidth / SIZE_TILE;
	UINT iMaxY = iHeight / SIZE_TILE;

	UINT iCurx = (m_iIdx % iMaxX);
	UINT iCury = (m_iIdx / iMaxX) % iMaxY;

	fPoint fptRenderPos = CCameraManager::getInst()->GetRenderPos(GetPos());
	fPoint fptScale = GetScale();

	BitBlt(hDc,
		(int)(fptRenderPos.x),
		(int)(fptRenderPos.y),
		(int)(fptScale.x),
		(int)(fptScale.y),
		(m_pTex->GetDC()),
		(int)(iCurx * SIZE_TILE),
		(int)(iCury * SIZE_TILE),
		SRCCOPY);
}

void CTile::SetTexture(CTexture* pTex)
{
	m_pTex = pTex;
}

void CTile::SetTileIdx(int idx)
{
	m_iIdx = idx;
}

void CTile::Save(FILE* pFile)
{
	fwrite(&m_iIdx, sizeof(int), 1,pFile);
}

void CTile::Load(FILE* pFile)
{
	fread(&m_iIdx, sizeof(int), 1, pFile);
}
