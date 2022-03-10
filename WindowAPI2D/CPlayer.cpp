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
	m_pTex = CResourceManager::getInst()->LoadTexture(L"PlayerTex",L"\\texture\\Animation\\MarioPlayer.bmp"); //�ε�Ȱ��� playerTex�� �̸��� ������(���� ������), ��θ� �����ϰ� ����(�ؽ���)����� 
	
	m_dVelocity = 50;
	m_gravite = 0;
	m_UpSpeed = 400;
	
	SetScale(fPoint(60.f, 60.f));
	
	Isfly = false;
	IsRight = true;	

	//�浹ü
	CreateCollider();
	GetCollider()->SetScale(fPoint(30.f, 30.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 0.f));
	
	//�ִϸ��̼�
	CreateAnimator();						//�̸� �Ӽ� ������ġ �ڸ���ġ �ӵ�,�̰� �ִϸ� ����
	GetAnimator()->CreateAnimation(L"Left_Move", m_pTex, fPoint(180.f, 0.f), fPoint(60.f, 60.f), fPoint(60.f, 0.f), 0.25f, 3);
	GetAnimator()->CreateAnimation(L"Right_Move", m_pTex, fPoint(0.f, 60.f), fPoint(60.f, 60.f), fPoint(60.f, 0.f), 0.25f, 3);
	GetAnimator()->CreateAnimation(L"Idle_left", m_pTex, fPoint(0.f, 0.f), fPoint(60.f, 60.f), fPoint(60.f, 0.f), 0.5f, 1);
	GetAnimator()->CreateAnimation(L"Idle_Right", m_pTex, fPoint(360.f, 60.f), fPoint(60.f, 60.f), fPoint(60.f, 0.f), 0.5f, 1);
	

	//�̰� �����ٴ°� �ִϸ��̼� ����
	/*CAnimation* pAni;
	pAni = GetAnimator()->FindAnimation(L"Right_Move");
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -10.f);*/
	
	//�̰� �÷��̾� �������� ī�޶� �����ϴ� ��
	//CCameraManager::getInst()->SetTargetobj(this);
}

CPlayer::~CPlayer()
{
	
}

void CPlayer::Update()
{
	fPoint pos = GetPos();
	
	//�ִϸ� ������ȯ
	if (IsRight)
		GetAnimator()->Play(L"Idle_Right");
	else
		GetAnimator()->Play(L"Idle_left");
	
	//�¿�� �����̱�
	if (KEY(VK_LEFT))
	{
		pos.x -= m_dVelocity * DT;
		GetAnimator()->Play(L"Left_Move");	
		IsRight = false;
	}
	if (KEY(VK_RIGHT))
	{
		pos.x += m_dVelocity * DT;
		GetAnimator()->Play(L"Right_Move");
		IsRight = true;
	}

	//���� ���� ���߿� ã�ƺ�����
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
	//�÷��̾� �׸� �׸���
	int width = m_pTex->GetBmpWidth();
	int height = m_pTex->GetBmpHeight();

	//�׳� �׸�
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
		//���Ϳ� �浹
	}
}

void CPlayer::OnCollisionExit(CCollider* pOther)
{
}
