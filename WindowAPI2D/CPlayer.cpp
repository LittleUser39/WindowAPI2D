#include "framework.h"
#include "CPlayer.h"
#include "CScene.h"
#include "CMissile.h"


CPlayer::CPlayer()
{
	m_dVelocity = 100;
	SetScale(fPoint(50, 50));
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
	Rectangle(hDc,
		(int)(GetPos().x -  GetScale().x / 2),
		(int)(GetPos().y -  GetScale().y / 2),
		(int)(GetPos().x +  GetScale().x / 2),
		(int)(GetPos().y +  GetScale().y / 2));
}

void CPlayer::CreateMissile()
{
	
}
