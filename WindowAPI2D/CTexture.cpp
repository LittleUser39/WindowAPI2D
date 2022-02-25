#include "framework.h"
#include "CTexture.h"

CTexture::CTexture()
{
	m_hDc = 0;
	m_hBmp = 0;
}

CTexture::~CTexture()
{
	DeleteDC(m_hDc);
	DeleteObject(m_hBmp);
}

HDC CTexture::GetDC()
{
	return m_hDc;
}

HBITMAP CTexture::GetBitMap()
{
	return m_hBmp;
}

void CTexture::Load(const wstring& strFillPath)
{
	//(핸들인스턴스값,파일의 경로(문자배열로 바꿔줌),이미지 타입(비트맵,도트 이미지),이미지의 크기x,y, 이미지의 속성(몰루?))
	m_hBmp = (HBITMAP)LoadImage(nullptr, strFillPath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	if (m_hBmp == 0) //이미지를 로드하는데 실패
		assert(nullptr);
}
