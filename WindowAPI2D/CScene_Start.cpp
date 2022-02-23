#include "framework.h"
#include "CScene_Start.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CMonster.h"
CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
	
}

void CScene_Start::Enter()
{
	

	//player 추가
	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(fPoint(500, 100));

	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);

	//monster 추가
	CMonster* pMonster = new CMonster;

	pMonster->SetPos(fPoint(1100, 300));
	pMonster->SetCenterPos(fPoint(pMonster->GetPos()));

	AddObject(pMonster, GROUP_GAMEOBJ::MONSTER);
}

void CScene_Start::Exit()
{
	
}
