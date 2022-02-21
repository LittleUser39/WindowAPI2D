#pragma once
class CGameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;

public:
	CGameObject();
	CGameObject(fPoint pos, fPoint scale);
	~CGameObject();

	virtual void Update() = 0;	//가상함수 - 상속받은 애가 오버라이딩해서 함수 이용 
	virtual void Render(HDC hDc) = 0;

	void SetPos(fPoint pos);		//해당 위치로 변경
	void SetScale(fPoint scale);	//해당 크기로 변경

	fPoint GetPos();				//해당 위치 가져옴
	fPoint GetScale();				//해당 크기 가져옴
};

