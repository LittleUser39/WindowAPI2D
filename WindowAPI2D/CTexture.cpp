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
	//(�ڵ��ν��Ͻ���,������ ���(���ڹ迭�� �ٲ���),�̹��� Ÿ��(��Ʈ��,��Ʈ �̹���),�̹����� ũ��x,y, �̹����� �Ӽ�(����?))
	m_hBmp = (HBITMAP)LoadImage(nullptr, strFillPath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	assert(m_hBmp);		// �̹����� ���ٸ� assert

	//��Ʈ���� ������ bmpinfo�� �˾ƾ���
	//�ھ�� ������ �ִ� ���� HDC������
	m_hDc = CreateCompatibleDC(CCore::getInst()->GetMainDC());

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hDc, m_hBmp);

	//��Ʈ�� ���� ����
	GetObject(m_hBmp, sizeof(BITMAP), &m_bmpInfo);
}
