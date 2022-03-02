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

	pPlayer->SetPos(fPoint(WINSIZEX/2, 900));

	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);

	//monster 추가
	CMonster* pMonster = new CMonster;

	pMonster->SetPos(fPoint(WINSIZEX/2, 200));
	pMonster->SetCenterPos(fPoint(pMonster->GetPos()));

	AddObject(pMonster, GROUP_GAMEOBJ::MONSTER);
}

void CScene_Start::Exit()
{
	
}
