#include "framework.h"
#include "CScene_Start.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CBackGround.h"
#include "Mario.h"
#include "CSound.h"
CScene_Start::CScene_Start()
{

}

CScene_Start::~CScene_Start()
{
	
}

CSound* pSound;

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
	if (KEYDOWN('Z'))
	{
		CSoundManager::getInst()->AddSound(L"BGM_1", L"sound\\th06_01.wav", false);
		CSoundManager::getInst()->Play(L"BGM_1");
		
	}
	if (KEYDOWN('C'))
	{
		
	}
}

void CScene_Start::Enter() //�� ��鿡 �ʿ��� �͵��� ���� �־���
{
	//�� �ҷ�����
	wstring path = CPathManager::getInst()->GetContentPath();
	path += L"\\tile\\test.tile";
	LoadTile(path);
	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(fPoint(WINSIZEX / 2, 900));
	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);

	//monster �߰�
	CMonster* pMonster = new CMonster;

	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::MONSTER);
	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::MISSILE_PLAYER, GROUP_GAMEOBJ::MONSTER);

	//ī�޶� �⺻ ���۽� ȭ�� �߰����μ���
	CCameraManager::getInst()->SetLookAt(fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f));
	CCameraManager::getInst()->FadeIn(2.f);
	
	
}

void CScene_Start::Exit()
{
	DeleteAll();
	
	CCollisionManager::getInst()->Reset();
}
