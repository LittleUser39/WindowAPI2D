#include "framework.h"
#include "CPanelUI.h"

CPanelUI::CPanelUI()
{
	m_fptDragStart = {};
}


CPanelUI::~CPanelUI()
{
}

CPanelUI* CPanelUI::Clone()
{
	
	return new CPanelUI(*this);
}

void CPanelUI::MouseOn()
{
	if (IsLbtnDown())//���� ���콺�� ����ִ� ��Ȳ
	{
		fPoint fptDiff = MousePos() - m_fptDragStart;

		fPoint fptCurPos = GetPos();
		fptCurPos += fptDiff;
		SetPos(fptCurPos);

		m_fptDragStart = MousePos();
	}
}

void CPanelUI::MouseLbtnDown()
{
	m_fptDragStart = MousePos();
}

void CPanelUI::MouseLbtnUp()
{
}
