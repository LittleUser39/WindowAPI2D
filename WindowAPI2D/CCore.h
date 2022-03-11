#pragma once

class CTexture;

class CCore
{
	SINGLETON(CCore);

	

private:
	HDC			m_hDC;		//À©µµ¿ì dc
	CTexture* m_pMemTex;

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