#pragma once
//함수로 쓰면 디버그 모드에서 언제 변환 되는지 확인할수 있다.
class CGameObject
{
private:
	fPoint m_fptPos;			//위치 값
	fPoint m_fptScale;			//크기 값

public:
	CGameObject();
	CGameObject(fPoint pos, fPoint scale);
	~CGameObject();

	virtual void Update() ;	//가상함수 - 상속받은 애가 오버라이딩해서 함수 이용 
	virtual void Render(HDC hDc) ; //이게 오브젝트들을 그리는 함수 (매개변수 DC)

	void SetPos(fPoint pos);		//해당 위치로 변경
	void SetScale(fPoint scale);	//해당 크기로 변경

	fPoint GetPos();				//해당 위치 가져옴
	fPoint GetScale();				//해당 크기 가져옴
};

