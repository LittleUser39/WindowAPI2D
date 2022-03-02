#pragma once


class CCore
{
	SINGLETON(CCore);

	

private:
	HDC			m_hDC;		//������ dc
	HDC			m_hMemDC;	//�޸� dc
	HBITMAP		m_hBMP;		//�޸� ��Ʈ��

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
	HBRUSH GetBrush(TYPE_BRUSH brush);
};