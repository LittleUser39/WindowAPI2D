#include "framework.h"
#include "CPlayer.h"
#include "CScene.h"
#include "CMissile.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"

CPlayer::CPlayer()
{
	SetName(L"Player");
	m_pTex = CResourceManager::getInst()->LoadTexture(L"PlayerTex",L"\\texture\\Animation\\MarioPlayer.bmp"); //로드된것은 playerTex로 이름이 정해짐(값도 정해짐), 경로를 설정하고 파일(텍스쳐)골라줌 
	
	m_dVelocity = 50;
	m_gravite = 0;
	SetScale(fPoint(60.f, 60.f));
	m_directspeed=(fPoint(0,0));
	Isfly = false;
	m_UpSpeed = 400;

	//충돌체
	CreateCollider();
	GetCollider()->SetScale(fPoint(30.f, 30.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 0.f));
	
	//애니메이션
	CreateAnimator();						//이름 속성 시작위치 자를위치 속도,이건 애니메 갯수
	GetAnimator()->CreateAnimation(L"Left_Move", m_pTex, fPoint(180.f, 0.f), fPoint(60.f, 60.f), fPoint(60.f, 0.f), 0.25f, 3);
	GetAnimator()->CreateAnimation(L"Right_Move", m_pTex, fPoint(0.f, 60.f), fPoint(60.f, 60.f), fPoint(60.f, 0.f), 0.25f, 3);
	GetAnimator()->CreateAnimation(L"Idle_left", m_pTex, fPoint(0.f, 0.f), fPoint(60.f, 60.f), fPoint(60.f, 0.f), 0.5f, 1);
	GetAnimator()->CreateAnimation(L"Idle_Right", m_pTex, fPoint(360.f, 60.f), fPoint(60.f, 60.f), fPoint(60.f, 0.f), 0.5f, 1);
	//GetAnimator()->Play(L"Idle_left");

	//이게 점프뛰는거 애니메이션 조종
	/*CAnimation* pAni;
	pAni = GetAnimator()->FindAnimation(L"Right_Move");
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -10.f);*/
	
	//이게 플레이어 기준으로 카메라를 세팅하는 것
	//CCameraManager::getInst()->SetTargetobj(this);
}

CPlayer::~CPlayer()
{
	
}

void CPlayer::Update()
{
	fPoint pos = GetPos();
	
	
	GetAnimator()->Play(L"Idle_Right");

	if (KEY(VK_LEFT))
	{
		pos.x -= m_dVelocity * DT;
		GetAnimator()->Play(L"Left_Move");	//이게 실행하는거 이름넣으면 그거 실행됨
	}
	if (KEY(VK_RIGHT))
	{
		pos.x += m_dVelocity * DT;
		GetAnimator()->Play(L"Right_Move");
	}

	//점프 구현 나중에 찾아봐야함
	if (KEY(VK_UP))
	{
		pos.y -= m_UpSpeed * DT;
		
	}
	else if(KEYDOWN(VK_UP))
	{
		m_gravite += 200 * DT;
		pos.y += m_gravite * DT;

	}
	if (KEY(VK_DOWN))
	{
		
	}

	SetPos(pos);
	if (KEYDOWN('X'))
	{
		CreateMissile();
	}
	GetAnimator()->Update();
}

void CPlayer::Render(HDC hDc)
{
	//todo 플레이어 그림 그리기
	int width = m_pTex->GetBmpWidth();
	int height = m_pTex->GetBmpHeight();

	//그냥 그림
	/*TransparentBlt(hDc,
		(int)(GetPos().x - (float)(width / 2)),
		(int)(GetPos().y - (float)(height / 2)),
		width, height,
		m_pTex->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255));*/

	component_render(hDc);
}

CPlayer* CPlayer::Clone()
{
	return new CPlayer(*this);
}

void CPlayer::CreateMissile()
{
	fPoint fpMissilePos = GetPos();
	fpMissilePos.x += GetScale().x / 2.f;

	// Misiile Object
	CMissile* pMissile = new CMissile;
	pMissile->SetPos(fpMissilePos);
	pMissile->SetDir(fVec2(1, 0));

	CreateObj(pMissile, GROUP_GAMEOBJ::MISSILE_PLAYER);
}

void CPlayer::OnCollision(CCollider* pOther)
{
}

void CPlayer::OnCollisionEnter(CCollider* pOther)
{
	if (L"Monster" == pOther->GetGameObject()->GetName())
	{
		//몬스터와 충돌
	}
}

void CPlayer::OnCollisionExit(CCollider* pOther)
{
}
