#include "framework.h"
#include "CTextObj.h"

CTextObj::CTextObj()
{
	
}

CTextObj::~CTextObj()
{
}

void CTextObj::Update()
{
}

void CTextObj::Render(HDC hDc)
{
	//오류난 이유 글자 크기가 이 배열을 넘어서 그럼	
	WCHAR title[22];
	swprintf_s(title, L" Press Space to Start");
	TextOutW(hDc, WINSIZEX / 2 - 140, WINSIZEY / 2, title, 21); //끝에 있는 숫자가 표시할 글자수
	
}
