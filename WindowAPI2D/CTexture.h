#pragma once
#include "CResource.h"
class CTexture : public CResource
{
private:
	HDC		m_hDc;	//HDC�ڵ鰪
	HBITMAP m_hBmp; //�̹����� �����ϴ� ���� SET �������� - �ε������� �˾Ƽ� ������

public:
	CTexture();
	virtual ~CTexture();

	HDC GetDC();
	HBITMAP GetBitMap();

	void Load(const wstring& strFillPath); //�ش��θ� �ָ� �װ���� �̹����� �ε�

};

