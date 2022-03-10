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
	//���콺�� �ö����� ��ư�� ���̶���Ʈ ǥ��
}

void CButtonUI::MouseOn()
{
	//���� ��ư ���
}

void CButtonUI::MouseLbtnDown()
{
	//�ٽ� ���� ���
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
