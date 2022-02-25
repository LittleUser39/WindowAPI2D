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
	//(�ڵ��ν��Ͻ���,������ ���(���ڹ迭�� �ٲ���),�̹��� Ÿ��(��Ʈ��,��Ʈ �̹���),�̹����� ũ��x,y, �̹����� �Ӽ�(����?))
	m_hBmp = (HBITMAP)LoadImage(nullptr, strFillPath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	if (m_hBmp == 0) //�̹����� �ε��ϴµ� ����
		assert(nullptr);
}
