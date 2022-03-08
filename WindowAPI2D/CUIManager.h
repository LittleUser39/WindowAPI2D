#pragma once

class CUI;

class CUIManager
{
	SINGLETON(CUIManager);
	
	
public:
	void Update();

private:
	CUI* GetTargetUI(CUI* pParentUI);
	

};

