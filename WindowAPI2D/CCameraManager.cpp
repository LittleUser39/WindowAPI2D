#include "framework.h"
#include "CCameraManager.h"
#include "CGameObject.h"
#include "CTexture.h"
CCameraManager::CCameraManager()
{
	m_fptLookAt = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);
	m_fptCurLookAt = m_fptLookAt;
	m_fptPrevLookAt = m_fptLookAt;
	m_pTargetobj = nullptr;
	m_fAccTime = m_fTime;
	m_fSpeed = 0;

	
}

CCameraManager::~CCameraManager()
{
	
}

void CCameraManager::init()
{
	m_pTex = CResourceManager::getInst()->CreateTexture(L"CameraTex", WINSIZEX, WINSIZEY);
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

void CCameraManager::Render(HDC hDc)
{

	if (CAM_EFFECT::NONE == m_eEffect)
		return;
	m_fCurTime += fDT;
	if (m_fEffectDuration < m_fCurTime)
	{
		m_eEffect = CAM_EFFECT::NONE;
		return;
	}
	float fRatio = m_fCurTime / m_fEffectDuration;
	int iAlpha;

	if (CAM_EFFECT::FADE_OUT == m_eEffect)
	{
		iAlpha = (int)(255.f * fRatio);
	}
	else if (CAM_EFFECT::FADE_IN==m_eEffect)
	{
		iAlpha = (int)(255.f * (1.f - fRatio));
	}

	BLENDFUNCTION bf = {};

	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = 0;
	bf.SourceConstantAlpha = iAlpha;

	AlphaBlend(hDc
		, 0, 0
		, (int)(m_pTex->GetBmpWidth())
		, (int)(m_pTex->GetBmpHeight())
		, m_pTex->GetDC()
		, 0, 0
		, (int)(m_pTex->GetBmpWidth())
		, (int)(m_pTex->GetBmpHeight())
		, bf);
}

void CCameraManager::SetLookAt(fPoint lookat)
{
	m_fptLookAt = lookat;
	float fMoveDist = (m_fptLookAt - m_fptPrevLookAt).Length();
	m_fAccel = fMoveDist / m_fTime;		// 등가속도 계산
	m_fAccel *= m_fAccDir;

	if (m_fAccDir < 0) // 초기 속도 세팅
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

void CCameraManager::Scroll(fVec2 vec, float velocity)
{
	m_fptLookAt = m_fptLookAt + vec * velocity * fDT;
	m_fptCurLookAt = m_fptCurLookAt + vec * velocity * fDT;

	fPoint fptCenter = fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f);
	m_fptDiff = m_fptCurLookAt - fptCenter;
}

void CCameraManager::FadeIn(float duration)
{
	m_eEffect = CAM_EFFECT::FADE_IN;
	m_fEffectDuration = duration;
	m_fCurTime = 0;
}

void CCameraManager::FadeOut(float duration)
{
	m_eEffect = CAM_EFFECT::FADE_OUT;
	m_fEffectDuration = duration;
	m_fCurTime = 0;
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

	// 시간이 지났거나 방향 벡터의 크기가 0이라면, 도착한것으로 간주. 속도를 0으로
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

	// 등가속도만큼 이전속도에 더해줌.
	m_fSpeed = m_fPreSpeed += m_fAccel * fDT;
}
