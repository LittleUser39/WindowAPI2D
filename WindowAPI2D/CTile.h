#pragma once
#include "CGameObject.h"
	class CTexture;

class CTile : public CGameObject
{
private:
	CTexture* m_pTex;
	int m_iIdx;

public:
	const static int SIZE_TILE = 32;
	
	CTile();
	virtual ~CTile();

	virtual CTile* Clone();
	virtual void Update();
	virtual void Render(HDC hDc);

	void SetTexture(CTexture* pTex);
	void SetTileIdx(int idx);
};

