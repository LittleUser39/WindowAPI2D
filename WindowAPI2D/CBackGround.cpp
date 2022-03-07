#include "framework.h"
#include "CBackGround.h"
#include "CTexture.h"
CBackGround::CBackGround()
{
	m_pTex = CResourceManager::getInst()->LoadTexture(L"Stage1", L"\\texture\\BackGround_1.bmp");
}

CBackGround::~CBackGround()
{
}

void CBackGround::Render(HDC hDc)
{
	//todo 플레이어 그림 그리기
	int width = m_pTex->GetBmpWidth();
	int height = m_pTex->GetBmpHeight();

	//그냥 그림
	TransparentBlt(hDc,
		(int)(GetPos().x - (float)(width / 2)),
		(int)(GetPos().y - (float)(height / 2)),
		width, height,
		m_pTex->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255));

	//component_render(hDc);
}

void CBackGround::Update()
{
}

CGameObject* CBackGround::Clone()
{
	return nullptr;
}
