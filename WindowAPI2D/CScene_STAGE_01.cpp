#include "framework.h"
#include "CScene_STAGE_01.h"
#include "CGameObject.h"
CScene_STAGE_01::CScene_STAGE_01()
{
}

CScene_STAGE_01::~CScene_STAGE_01()
{
}

void CScene_STAGE_01::Enter()
{
	CGameObject* obj = new CGameObject;

	obj->SetPos(fPoint(200, 200));
	obj->SetScale(fPoint(100, 100));

	AddObject(obj, GROUP_GAMEOBJ::DEFAULT);
}

void CScene_STAGE_01::Exit()
{
	ClearObject();
}
