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

void CScene_Start::Enter() //이 장면에 필요한 것들을 전부 넣어줌
{
	//맵 불러오기
	wstring path = CPathManager::getInst()->GetContentPath();
	path += L"\\tile\\test.tile";
	LoadTile(path);

	//player 추가
	Mario* pMario = new Mario;
	pMario->SetPos(fPoint(100, 650));
	AddObject(pMario, GROUP_GAMEOBJ::PLAYER);

	//monster 추가
	CMonster* pMonster = new CMonster;
	pMonster->SetPos(fPoint(300, 650));
	pMonster->SetCenterPos(pMonster->GetPos());
	AddObject(pMonster, GROUP_GAMEOBJ::MONSTER);

	//클론 때문에 오류가 났음 일단 주석처리
	/*CMonster* othermonster = pMonster->Clone();
	othermonster->SetPos(fPoint(400, 650));
	AddObject(othermonster, GROUP_GAMEOBJ::MONSTER);*/

	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::MONSTER);
	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::MISSILE_PLAYER, GROUP_GAMEOBJ::MONSTER);

	//카메라 기본 시작시 화면 중간으로설정
	CCameraManager::getInst()->SetLookAt(fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f));
	CCameraManager::getInst()->FadeIn(2.f);
	
	
}

void CScene_Start::Exit()
{
	DeleteAll();
	
	CCollisionManager::getInst()->Reset();
}
