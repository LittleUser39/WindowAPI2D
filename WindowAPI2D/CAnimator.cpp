#include "framework.h"
#include "CAnimator.h"
#include "CAnimation.h"

CAnimator::CAnimator()
{
	m_pOwner = nullptr;
	m_pCurAni = nullptr;
}

CAnimator::~CAnimator()
{
	for (map<wstring, CAnimation*>::iterator iter = m_mapAni.begin(); iter != m_mapAni.end(); iter++)
	{
		if (nullptr != iter->second)
			delete iter->second;
	}
	m_mapAni.clear();
}

CGameObject* CAnimator::GetObj()
{
	return m_pOwner;
}

void CAnimator::Render(HDC hDc)
{
	if (nullptr != m_pCurAni)
	{
		m_pCurAni->Render(hDc);
	}
}

void CAnimator::Update()
{
	if (nullptr != m_pCurAni)
	{
		m_pCurAni->Update();
	}
}

void CAnimator::CreateAnimation(const wstring& strName, CTexture* pTex, fPoint lt, fPoint slice, fPoint step, float duration, UINT frmcount)
{
	CAnimation* pAni = FindAnimation(strName);
	if (nullptr != pAni)
	{
		// �̸��� �Ȱ��� �ִϸ��̼��� ���� �� ����
		// 1.�̹��ִ��� ����� ���ο� �ִϸ��̼� �־��ֱ�
		// 2.�̹� �����ϱ� �׳� ����
		// 3.�ִµ� �ִ°� �ǵ��� ���� ������ assert
		assert(nullptr);
	}

	pAni = new CAnimation;

	pAni->SetName(strName);
	pAni->m_pAnimator = this;
	pAni->Create(pTex, lt, slice, step, duration, frmcount);

	m_mapAni.insert(make_pair(strName, pAni));
}

CAnimation* CAnimator::FindAnimation(const wstring& strname)
{
	map<wstring, CAnimation*>::iterator iter = m_mapAni.find(strname);

	if (iter == m_mapAni.end())
	{
		return nullptr;
	}
	return iter->second;
}

void CAnimator::Play(const wstring& strname)
{
	m_pCurAni = FindAnimation(strname);
}
