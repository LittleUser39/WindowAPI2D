#pragma once
#include "CResource.h"
class CTexture : public CResource
{
private:
	HDC		m_hDc;	//HDC�ڵ鰪
	HBITMAP m_hBmp; //�̹����� �����ϴ� ���� SET �������� - �ε������� �˾Ƽ� ������
	BITMAP m_bmpInfo;

public:
	CTexture();
	virtual ~CTexture();

	HDC GetDC();
	HBITMAP GetBitMap();
	BITMAP GetBitMapInfo();

	int GetBmpWidth();
	int GetBmpHeight();

	void Load(const wstring& strFillPath); //�ش��θ� �ָ� �װ���� �̹����� �ε�

};

