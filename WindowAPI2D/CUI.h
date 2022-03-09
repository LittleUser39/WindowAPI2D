#pragma once
#include "CGameObject.h"
class CUI : public CGameObject
{
	friend class CUIManager;

private:
	vector<CUI*>	m_vecChildUI;	//	ui�� �ڽ��� �����ϴ� ����
	CUI*			m_pParentUI;	//	ui�� �θ�

	fPoint			m_fptFinalPos;	//	���� ���� �׷������ ��ġ

	bool           m_bCameraAffected;	//ī�޶��� ������ �޴°�
	bool		   m_bLbtnDown;			//ui�� ���������ӿ� ���Ⱦ���.
	bool		   m_bMouseOn;			//ui�� ���������ӿ� ���콺�� �÷��� �־���.
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

	//����� �ൿ
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

