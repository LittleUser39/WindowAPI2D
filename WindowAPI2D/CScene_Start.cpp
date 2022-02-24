#include "framework.h"
#include "CScene_Start.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CTextObj.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
	
}

void CScene_Start::Enter()
{
	CTextObj* title = new CTextObj;
	title->SetPos(fPoint(WINSIZEX / 2, WINSIZEY / 2));
	AddObject(title, GROUP_GAMEOBJ::DEFAULT);
}

void CScene_Start::Exit()
{
	
}
