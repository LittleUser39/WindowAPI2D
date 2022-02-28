#pragma once


class CCore
{
	SINGLETON(CCore);

	

private:
	HDC			m_hDC;		//윈도우 dc
	HDC			m_hMemDC;	//메모리 dc
	HBITMAP		m_hBMP;		//메모리 비트맵

	//GDI
	HPEN m_arrPen[(int)TYPE_PEN::SIZE];
	HBRUSH m_arrBrush[(int)TYPE_BRUSH::SIZE];

public:
	void update();
	void render();
	void init();

	HDC GetMainDC();

	void createBrushPen();
	HPEN GetPen(TYPE_PEN pen);
	HBRUSH GetABrush(TYPE_BRUSH brush);
};