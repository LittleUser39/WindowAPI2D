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
	//������ ���� ���� ũ�Ⱑ �� �迭�� �Ѿ �׷�	
	WCHAR title[22];
	swprintf_s(title, L" Press Space to Start");
	TextOutW(hDc, WINSIZEX / 2 - 140, WINSIZEY / 2, title, 21); //���� �ִ� ���ڰ� ǥ���� ���ڼ�
	
}
