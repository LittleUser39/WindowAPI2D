#pragma once
#include "CUI.h"

//정수 포인터를 위한 타입 정의
typedef void(*BTN_FUNC)(DWORD_PTR, DWORD_PTR);


class CButtonUI : public CUI
{

	BTN_FUNC m_pFunc;	//함수 포인터
	DWORD_PTR m_pParam1;
	DWORD_PTR m_pParam2;

public:
	CButtonUI();
	~CButtonUI();

	virtual void MouseOn();
	virtual void MouseLbtnDown();
	virtual void MouseLbtnUp();
	virtual void MouseLbtnClick();

	void SetClickCallBack(BTN_FUNC pFunc, DWORD_PTR param1, DWORD_PTR param2);
};

