#include "framework.h"
#include "CPlayer.h"
#include "CScene.h"
#include "CMissile.h"
#include "CTexture.h"
#include "CCollider.h"

CPlayer::CPlayer()
{
	SetName(L"Player");
	m_pTex = CResourceManager::getInst()->LoadTexture(L"PlayerTex",L"\\texture\\Player.bmp"); //�ε�Ȱ��� playerTex�� �̸��� ������(���� ������), ��θ� �����ϰ� ����(�ؽ���)����� 
	
	m_dVelocity = 100;
	SetScale(fPoint(70.f, 70.f));

	CreateCollider();
	GetCollider()->SetScale(fPoint(40.f, 40.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 10.f));
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

}

void CPlayer::Render(HDC hDc)
{
	//todo �÷��̾� �׸� �׸���
	int width = m_pTex->GetBmpWidth();
	int height = m_pTex->GetBmpHeight();

	//BitBlt(hDc, GetPos().x - width / 2.f, GetPos().y - height / 2.f, width, height, m_pTex->GetDC(), 0, 0, SRCCOPY);
	TransparentBlt(hDc,
		(int)(GetPos().x - (float)(width / 2)),
		(int)(GetPos().y - (float)(height / 2)),
		width, height,
		m_pTex->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255));

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
