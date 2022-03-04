#include "framework.h"
#include "CCameraManager.h"
CCameraManager::CCameraManager()
{
	m_fptLookAt = {};
	m_pTargetobj = nullptr;
}

CCameraManager::~CCameraManager()
{

}

void CCameraManager::SetLookAt(fPoint lookat)
{
	m_fptLookAt = lookat;
}

void CCameraManager::SetTargetobj(CGameObject* target)
{
	m_pTargetobj = target;
}
