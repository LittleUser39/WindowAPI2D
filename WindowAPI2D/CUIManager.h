#pragma once

class CUI;

class CUIManager
{
	SINGLETON(CUIManager);
	
	CUI* m_pFocusedUI;
public:
	void Update();
	void SetFocusedUI(CUI* pUI);

private:
	CUI* GetTargetUI(CUI* pParentUI);
	CUI* GetFocusedUI();

};

