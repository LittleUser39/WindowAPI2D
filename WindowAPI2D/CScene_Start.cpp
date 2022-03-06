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

void CScene_Start::Update()
{
	CScene::Update();

	if (KEYDOWN(VK_SPACE))
	{
		ChangeScn(GROUP_SCENE::TOOL);
	}
	if (KEYDOWN(VK_LBUTTON))
	{
		fPoint fptLookAt = CCameraManager::getInst()->GetRealPos(MousePos());
		CCameraManager::getInst()->SetLookAt(fptLookAt);
	}
}

void CScene_Start::Enter()
{

	//player �߰�
	CPlayer* pPlayer = new CPlayer;
	pPlayer->SetPos(fPoint(100, 650));
	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);

	//monster �߰�
	CMonster* pMonster = new CMonster;
	pMonster->SetPos(fPoint(300, 650));
	pMonster->SetCenterPos(pMonster->GetPos());
	AddObject(pMonster, GROUP_GAMEOBJ::MONSTER);

	CMonster* othermonster = pMonster->Clone();
	othermonster->SetPos(fPoint(400, 650));
	AddObject(othermonster, GROUP_GAMEOBJ::MONSTER);

	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::MONSTER);
	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::MISSILE_PLAYER, GROUP_GAMEOBJ::MONSTER);

	//ī�޶� �⺻ ���۽� ȭ�� �߰����μ���
	CCameraManager::getInst()->SetLookAt(fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f));
}

void CScene_Start::Exit()
{
	DeleteAll();
	
}
