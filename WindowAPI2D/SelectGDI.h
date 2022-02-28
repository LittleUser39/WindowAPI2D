#pragma once
class SelectGDI
{
private:
	HDC m_hDc;
	HPEN m_hOldPen;
	HBRUSH m_hOldBrush;
public:
	SelectGDI(HDC hDc, TYPE_BRUSH brush)
	{
		m_hDc = hDc;
		HBRUSH hBrush = CCore::getInst()->GetABrush(brush);
		m_hOldBrush = (HBRUSH)SelectObject(hDc, hBrush);
	}
	SelectGDI(HDC hDc, TYPE_PEN pen)
	{
		m_hDc = hDc;
		HPEN hPen = CCore::getInst()->GetPen(pen);
		m_hOldBrush = (HBRUSH)SelectObject(hDc, hPen);
	}
	~SelectGDI()
	{
		SelectObject(m_hDc,m_hOldBrush);
		SelectObject(m_hDc,m_hOldPen);
	}

};

