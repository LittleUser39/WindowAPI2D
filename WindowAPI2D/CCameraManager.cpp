#include "framework.h"
#include "CCameraManager.h"
#include "CGameObject.h"

CCameraManager::CCameraManager()
{
	m_fptLookAt = {};
	m_pTargetobj = nullptr;
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
	
	//화면 중앙과 카메라 lookat 좌표 사이 차이 계산
	CalDiff();
}

void CCameraManager::SetLookAt(fPoint lookat)
{
	m_fptLookAt = lookat;
}

void CCameraManager::SetTargetobj(CGameObject* target)
{
	m_pTargetobj = target;
}

fPoint CCameraManager::GetRenderPos(fPoint objpos)
{
	return objpos - m_fptDiff;
}

void CCameraManager::CalDiff()
{
	fPoint fptCenter = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);

	m_fptDiff = m_fptLookAt - fptCenter;
}
