#include "framework.h"
#include "CPlayer.h"
#include "CScene.h"
#include "CMissile.h"
#include "CTexture.h"

CPlayer::CPlayer()
{
	m_pTex = new CTexture();
	wstring strFilePath = CPathManager::getInst()->GetContentPath();
	strFilePath += L"\\texture\\Player.bmp";
	m_pTex->Load(strFilePath);
	
	m_dVelocity = 100;
	SetScale(fPoint(50, 50));
}

CPlayer::~CPlayer()
{
	if (nullptr != m_pTex)
		delete m_pTex;
}

void CPlayer::Update()
{
	fPoint pos = GetPos();
	


	if (KEY(VK_LEFT))
	{
		pos.x -= m_dVelocity * DT;
	}
	if (KEY(VK_RIGHT))
	{
		pos.x += m_dVelocity * DT;
	}
	if (KEY(VK_UP))
	{
		pos.y -= m_dVelocity * DT;
	}
	if (KEY(VK_DOWN))
	{
		pos.y += m_dVelocity * DT;
	}

	SetPos(pos);
	if (KEYDOWN('X'))
	{
		CreateMissile();
	}

}

void CPlayer::Render(HDC hDc)
{
	//todo 플레이어 그림 그리기
	int width = m_pTex->GetBmpWidth();
	int height = m_pTex->GetBmpHeight();

	//BitBlt(hDc, GetPos().x - width / 2.f, GetPos().y - height / 2.f, width, height, m_pTex->GetDC(), 0, 0, SRCCOPY);
	TransparentBlt(hDc,
		(int)(GetPos().x - (float)(width / 2)),
		(int)(GetPos().y - (float)(height / 2)),
		width, height,
		m_pTex->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255));
}

void CPlayer::CreateMissile()
{
	fPoint fptMissilPos = GetPos();
	fptMissilPos.x += GetScale().x / 2.f;

	CMissile* pMissile = new CMissile;
	pMissile->SetPos(fptMissilPos);
	pMissile->SetDir(fVec2(1,0));
	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_GAMEOBJ::MISSILE);

	//피타고라스 정리를 이용하여 대각선으로 발사
	CMissile* pMisile2 = new CMissile;
	pMisile2->SetPos(fptMissilPos);
	pMisile2->SetDir(3.45);
	pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMisile2, GROUP_GAMEOBJ::MISSILE);
}
