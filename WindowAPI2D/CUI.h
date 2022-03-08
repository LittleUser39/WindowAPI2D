#pragma once
#include "CGameObject.h"
class CUI : public CGameObject
{
	friend class CUIManager;

private:
	vector<CUI*>	m_vecChildUI;	//	ui의 자식을 포함하는 백터
	CUI*			m_pParentUI;	//	ui의 부모

	fPoint			m_fptFinalPos;	//	내가 실제 그려줘야할 위치

	bool           m_bCameraAffected;	//카메라의 영향을 받는가
	bool		   m_bLbtnDown;			//ui가 이전프레임에 눌렸었다.
	bool		   m_bMouseOn;			//ui가 이전프레임에 마우스가 올려져 있었다.
public:
	CUI();
	CUI(const CUI& other);
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

	void SetCameraAffected(bool affected);
	fPoint GetFinalPos();
	CUI* GetParent();
	const vector<CUI*>GetChildUI();
	void AddChild(CUI* pUI);
	bool GetCameraAffected();
	bool IsMouseON();
	bool IsLbtnDown();

private:
	void MouseOnCheck();
};

