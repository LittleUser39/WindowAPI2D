#include "framework.h"
#include "CTexture.h"

CTexture::CTexture()
{
	m_hDc = 0;
	m_hBmp = 0;
	m_bmpInfo = {};
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

BITMAP CTexture::GetBitMapInfo()
{
	return m_bmpInfo;
}

int CTexture::GetBmpWidth()
{
	return m_bmpInfo.bmWidth;
}

int CTexture::GetBmpHeight()
{
	return m_bmpInfo.bmHeight;
}

void CTexture::Load(const wstring& strFillPath)
{
	//(핸들인스턴스값,파일의 경로(문자배열로 바꿔줌),이미지 타입(비트맵,도트 이미지),이미지의 크기x,y, 이미지의 속성(몰루?))
	m_hBmp = (HBITMAP)LoadImage(nullptr, strFillPath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	assert(m_hBmp);		// 이미지가 없다면 assert

	//비트맵을 가지고 bmpinfo를 알아야함
	//코어에서 가지고 있던 메인 HDC가져옴
	m_hDc = CreateCompatibleDC(CCore::getInst()->GetMainDC());

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hDc, m_hBmp);

	//비트맵 인포 추출
	GetObject(m_hBmp, sizeof(BITMAP), &m_bmpInfo);
}

void CTexture::Create(UINT width, UINT height)
{
	HDC mainDC = CCore::getInst()->GetMainDC();
	m_hBmp = CreateCompatibleBitmap(mainDC,width,height);
	m_hDc = CreateCompatibleDC(mainDC);

	HBITMAP hOldBmp = (HBITMAP)SelectObject(m_hDc, m_hBmp);
	DeleteObject(hOldBmp);

	GetObject(m_hBmp, sizeof(BITMAP), &m_bmpInfo);
}
