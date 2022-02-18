#pragma once


class CCore
{
	SINGLETON(CCore);

	

private:
	HDC			m_hDC;		//윈도우 dc
	HDC			m_hMemDC;	//메모리 dc
	HBITMAP		m_hBMP;		//메모리 비트맵

public:
	void update();
	void render();
	void init();
};