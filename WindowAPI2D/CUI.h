#pragma once
#include "CGameObject.h"
class CUI : public CGameObject
{
private:
	vector<CUI*>	m_vecChildUI;	//	ui의 자식을 포함하는 백터
	CUI*			m_pParentUI;	//	ui의 부모

	fPoint m_fptFinalPos;			//	내가 실제 그려줘야할 위치

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

