#include "framework.h"
#include "CButtonUI.h"

CButtonUI::CButtonUI()
{
	m_pFunc = nullptr;
	m_pParam1 = 0;
	m_pParam2 = 0;
}

CButtonUI::~CButtonUI()
{
	//마우스가 올라갔을때 버튼이 하이라이트 표시
}

void CButtonUI::MouseOn()
{
	//눌린 버튼 모양
}

void CButtonUI::MouseLbtnDown()
{
	//다시 원본 모양
}

void CButtonUI::MouseLbtnUp()
{

}

void CButtonUI::MouseLbtnClick()
{
	if (nullptr != m_pFunc)
		m_pFunc(m_pParam1, m_pParam2);
}

void CButtonUI::SetClickCallBack(BTN_FUNC pFunc, DWORD_PTR param1, DWORD_PTR param2)
{
	m_pFunc = pFunc;
	m_pParam1 = param1;
	m_pParam2 = param2;
}
