#pragma once
#include "CGameObject.h"
class CUI : public CGameObject
{
private:
	vector<CUI*>	m_vecChildUI;	//	ui�� �ڽ��� �����ϴ� ����
	CUI*			m_pParentUI;	//	ui�� �θ�

	fPoint m_fptFinalPos;			//	���� ���� �׷������ ��ġ

public:
	CUI();
	virtual ~CUI();

	virtual void Update();
	virtual void finalUpdate();

	virtual void Render(HDC hDc);
	virtual CUI* Clone();

	void Update_Child();
	void Render_Child(HDC hDc);
	void finalUpdate_Child();

	virtual void MouseOn();
	virtual void MouseLbtnDown();
	virtual void MouseLbtnUp();
	virtual void MouseLbtnClick();

	fPoint GetFinalPos();
	CUI* GetParent();

	void AddChild(CUI* pUI);
};

