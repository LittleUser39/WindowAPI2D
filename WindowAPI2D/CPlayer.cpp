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
	m_pTex = CResourceManager::getInst()->LoadTexture(L"PlayerTex",L"\\texture\\Animation\\Animation_Player.bmp"); //로드된것은 playerTex로 이름이 정해짐(값도 정해짐), 경로를 설정하고 파일(텍스쳐)골라줌 
	
	m_dVelocity = 100;
	SetScale(fPoint(70.f, 70.f));

	CreateCollider();
	GetCollider()->SetScale(fPoint(40.f, 40.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 10.f));

	CreateAnimator();																							//여기가 속도,이건 애니메 갯수
	GetAnimator()->CreateAnimation(L"Right_Move", m_pTex, fPoint(0.f, 210.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.5f, 3);
	GetAnimator()->Play(L"Right_Move");	//이게 실행하는거 이름넣으면 그거 실행됨

	CAnimation* pAni;
	pAni = GetAnimator()->FindAnimation(L"Right_Move");
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -10.f);
	
	CCameraManager::getInst()->SetTargetobj(this);
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
