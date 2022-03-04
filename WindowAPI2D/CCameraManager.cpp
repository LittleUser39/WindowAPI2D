#include "framework.h"
#include "CCameraManager.h"
#include "CGameObject.h"

CCameraManager::CCameraManager()
{
	m_fptLookAt	 = {};
	m_pTargetobj = nullptr;
	m_fTime		 = 2.f;
	m_fAccTime	 = m_fTime;
	m_fSpeed	 = 0;
	m_fPreSpeed	 = 0;
	m_fAccel	 = 0;
	m_fAccDir	 = 1.f;

}

CCameraManager::~CCameraManager()
{
	
}

void CCameraManager::Update()
{
	if (m_pTargetobj)
	{
		if (m_pTargetobj->isDead())
		{
			m_pTargetobj = nullptr;
		}
		else
		{
			SetLookAt(m_pTargetobj->GetPos());
		}
	}
	
	//ȭ�� �߾Ӱ� ī�޶� lookat ��ǥ ���� ���� ���
	CalDiff();
}

void CCameraManager::SetLookAt(fPoint lookat)
{
	m_fptLookAt = lookat;
	float fMoveDist = (m_fptLookAt - m_fptPrevLookAt).Length();
	m_fAccel = fMoveDist / m_fTime;		// ��ӵ� ���
	m_fAccel *= m_fAccDir;

	if (m_fAccDir < 0) // �ʱ� �ӵ� ����
	{
		m_fSpeed = fMoveDist;
	}
	else
	{
		m_fSpeed = 0.f;
	}
	m_fAccTime = 0.f;
}

void CCameraManager::SetTargetobj(CGameObject* target)
{
	m_pTargetobj = target;
}

fPoint CCameraManager::GetLookAt()
{
	return m_fptLookAt;
}

fPoint CCameraManager::GetRenderPos(fPoint objpos)
{
	return objpos - m_fptDiff;
}

fPoint CCameraManager::GetRealPos(fPoint renderpos)
{
	return renderpos + m_fptDiff;
}

void CCameraManager::CalDiff()
{
	m_fAccTime += fDT;

	fVec2 fvLookDir = m_fptLookAt - m_fptPrevLookAt;

	// �ð��� �����ų� ���� ������ ũ�Ⱑ 0�̶��, �����Ѱ����� ����. �ӵ��� 0����
	if (m_fTime <= m_fAccTime || fvLookDir.Length() == 0)
	{
		m_fptCurLookAt = m_fptLookAt;
		m_fSpeed = 0.f;
	}
	else
	{
		m_fptCurLookAt = m_fptPrevLookAt + fvLookDir.Nomarlize() * m_fSpeed * fDT;
	}

	fPoint fptCenter = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);

	m_fptDiff = m_fptCurLookAt - fptCenter;
	m_fptPrevLookAt = m_fptCurLookAt;
	m_fPreSpeed = m_fSpeed;

	// ��ӵ���ŭ �����ӵ��� ������.
	m_fSpeed = m_fPreSpeed += m_fAccel * fDT;
}
