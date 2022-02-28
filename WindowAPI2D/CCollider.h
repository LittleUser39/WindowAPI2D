#pragma once
class CGameObject;

class CCollider
{
	friend class CGameObject;

private:
	CGameObject* m_pOwner;
	fPoint m_fptOffsetPos;
	fPoint m_fptFinalPos;
	fPoint m_fptScale;

public:
	CCollider();
	~CCollider();

	fPoint GetOffsetPos();
	fPoint GetFinalPos();
	fPoint GetScale();

	fPoint SetOffsetPos(fPoint offset);
	fPoint SetFinalPos(fPoint pos);
	fPoint SetScale(fPoint scale);

	void finalUpdate();
	void Render(HDC hDc);
};

