#pragma once


class CCore
{
	SINGLETON(CCore);

	

private:
	HDC			m_hDC;		//������ dc
	HDC			m_hMemDC;	//�޸� dc
	HBITMAP		m_hBMP;		//�޸� ��Ʈ��

public:
	void update();
	void render();
	void init();
};