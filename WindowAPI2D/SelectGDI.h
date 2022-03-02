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
		HBRUSH hBrush = CCore::getInst()->GetBrush(brush);
		m_hOldBrush = (HBRUSH)SelectObject(hDc, hBrush);
		m_hOldPen = 0;
	}
	SelectGDI(HDC hDc, TYPE_PEN pen)
	{
		m_hDc = hDc;
		HPEN hPen = CCore::getInst()->GetPen(pen);
		m_hOldPen = (HPEN)SelectObject(hDc, hPen);
		m_hOldBrush = 0;
	}
	~SelectGDI()
	{
		SelectObject(m_hDc,m_hOldBrush);
		SelectObject(m_hDc,m_hOldPen);
	}

};

