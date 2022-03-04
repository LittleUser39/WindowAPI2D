#include "framework.h"
#include "CAnimation.h"
#include "CAnimator.h"
#include "CGameObject.h"
#include "CTexture.h"

CAnimation::CAnimation()
{
	m_strName	= L"";
	m_pAnimator = nullptr;
	m_pTex		= nullptr;
	m_iCurFrm	= 0;
	m_fAccTime	= 0;
}

CAnimation::~CAnimation()
{
}

void CAnimation::SetName(const wstring& strName)
{
	m_strName = strName;
}

const wstring& CAnimation::GetName()
{
	return m_strName;
}

void CAnimation::SetFrame(int frmIndex)
{
	m_iCurFrm = frmIndex;
}

tAniFrm& CAnimation::GetFrame(int frmIndex)
{
	return m_vecFrm[frmIndex];
}

void CAnimation::Update()
{
	//애니메이션 프레임 전환
	m_fAccTime += fDT;

	if (m_fAccTime > m_vecFrm[m_iCurFrm].fDuration)
	{
		m_fAccTime -= m_vecFrm[m_iCurFrm].fDuration;//다음프레임 가기전 프레임의 시간
		m_iCurFrm++;								//다음프레임
		m_iCurFrm %= m_vecFrm.size();				//애니메이션을 다 돌고 처음으로 돌아감 - 전체를 나눔	
	}
}

void CAnimation::Render(HDC hDc)
{
	CGameObject* pObj=m_pAnimator->GetObj();
	fPoint fptPos = pObj->GetPos();
	tAniFrm frm = m_vecFrm[m_iCurFrm];
	fptPos = fptPos + frm.fptOffset; //오프셋 만큼 조금 움직인후 그려줌

	TransparentBlt(hDc,
		(int)(fptPos.x - frm.fptSlice.x / 2.f),
		(int)(fptPos.y - frm.fptSlice.y / 2.f),
		(int)(frm.fptSlice.x),
		(int)(frm.fptSlice.y),
		m_pTex->GetDC(),
		(int)(frm.fptLT.x),
		(int)(frm.fptLT.y),
		(int)(frm.fptSlice.x),
		(int)(frm.fptSlice.y),
		RGB(255, 0, 255));
}

//					애니메이션 이미지, 시작프레임 좌상단,프레임의 크기, 프레임 반복위치,프레임 지속시간, 프레임 갯수						
void CAnimation::Create(CTexture* pTex, fPoint lt, fPoint slice,fPoint step, float duration, UINT frmcount)
{
	m_pTex = pTex;

	tAniFrm frm = {};
	for (UINT i = 0; i < frmcount; i++)
	{
		frm.fDuration = duration;
		frm.fptSlice = slice;
		frm.fptLT = lt + step * i;

		m_vecFrm.push_back(frm);
	}
}
