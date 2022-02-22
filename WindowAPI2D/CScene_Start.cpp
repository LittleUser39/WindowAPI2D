#include "framework.h"
#include "CScene_Start.h"
#include "CGameObject.h"
CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
	ClearObject();
}

void CScene_Start::Enter()
{
	CGameObject* obj = new CGameObject;

	obj->SetPos(fPoint(200, 200));
	obj->SetScale(fPoint(100, 100));

	AddObject(obj, GROUP_GAMEOBJ::DEFAULT);
}

void CScene_Start::Exit()
{
	ClearObject();
}
