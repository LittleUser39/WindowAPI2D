#include "framework.h"
#include "CPlayer.h"
#include "CScene.h"
#include "CMissile.h"


CPlayer::CPlayer()
{
	m_dVelocity = 100;
	SetScale(fPoint(50, 50));
}

CPlayer::~CPlayer()
{
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
	Rectangle(hDc,
		(int)(GetPos().x -  GetScale().x / 2),
		(int)(GetPos().y -  GetScale().y / 2),
		(int)(GetPos().x +  GetScale().x / 2),
		(int)(GetPos().y +  GetScale().y / 2));
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
	pMisile2->SetDir(8.145);
	pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMisile2, GROUP_GAMEOBJ::MISSILE);
}
