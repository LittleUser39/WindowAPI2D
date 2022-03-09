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
	//�ִϸ��̼� ������ ��ȯ
	m_fAccTime += fDT;

	if (m_fAccTime > m_vecFrm[m_iCurFrm].fDuration)
	{
		m_fAccTime -= m_vecFrm[m_iCurFrm].fDuration;//���������� ������ �������� �ð�
		m_iCurFrm++;								//����������
		m_iCurFrm %= m_vecFrm.size();				//�ִϸ��̼��� �� ���� ó������ ���ư� - ��ü�� ����	
	}
}

void CAnimation::Render(HDC hDc)
{
	CGameObject* pObj=m_pAnimator->GetObj();
	fPoint fptPos = pObj->GetPos();
	tAniFrm frm = m_vecFrm[m_iCurFrm];
	fptPos = fptPos + frm.fptOffset; //������ ��ŭ ���� �������� �׷���
	
	//ī�޶� �������� �׷������ϴ� ��ġ
	fPoint fptRenderPos = CCameraManager::getInst()->GetRenderPos(fptPos);
	
	TransparentBlt(hDc,
		(int)(fptRenderPos.x - frm.fptSlice.x / 2.f),
		(int)(fptRenderPos.y - frm.fptSlice.y / 2.f),
		(int)(frm.fptSlice.x),
		(int)(frm.fptSlice.y),
		m_pTex->GetDC(),
		(int)(frm.fptLT.x),
		(int)(frm.fptLT.y),
		(int)(frm.fptSlice.x),
		(int)(frm.fptSlice.y),
		RGB(255, 0, 255));
}

//					�ִϸ��̼� �̹���, ���������� �»��,�������� ũ��, ������ �ݺ���ġ,������ ���ӽð�, ������ ����						
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