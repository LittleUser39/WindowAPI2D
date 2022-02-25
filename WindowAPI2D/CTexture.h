#pragma once
#include "CResource.h"
class CTexture : public CResource
{
private:
	HDC		m_hDc;	//HDC핸들값
	HBITMAP m_hBmp; //이미지를 저장하는 변수 SET 없는이유 - 로드했을때 알아서 정해짐
	BITMAP m_bmpInfo;

public:
	CTexture();
	virtual ~CTexture();

	HDC GetDC();
	HBITMAP GetBitMap();
	BITMAP GetBitMapInfo();

	int GetBmpWidth();
	int GetBmpHeight();

	void Load(const wstring& strFillPath); //해당경로를 주면 그경로의 이미지를 로드

};

