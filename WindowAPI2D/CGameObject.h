#pragma once
//함수로 쓰면 디버그 모드에서 언제 변환 되는지 확인할수 있다.

class CCollider;

class CGameObject
{
private:
	fPoint m_fptPos;			//위치 값
	fPoint m_fptScale;			//크기 값

	CCollider* m_pCollider;	//충돌체가 있으면 주소를 없으면 nullptr

public:
	CGameObject();
	virtual ~CGameObject();	//virtual 하는 이유 부모 소멸자 말고 자식 소멸자를 사용하기 위해

	virtual void Update() = 0;	//가상함수 - 상속받은 애가 오버라이딩해서 함수 이용 
	virtual void finalUpdate()	final;	//상속받은 클래스가 더이상 오버라이딩 하는것을 막아주는 키워드
	virtual void Render(HDC hDc) ; //이게 오브젝트들을 그리는 함수 (매개변수 DC)
	virtual void component_render(HDC hDc);

	void SetPos(fPoint pos);		//해당 위치로 변경
	void SetScale(fPoint scale);	//해당 크기로 변경

	fPoint GetPos();				//해당 위치 가져옴
	fPoint GetScale();				//해당 크기 가져옴
	CCollider* GetCollider();		//가지고 있는 충돌체 넣어줌
	void CreateCollider();			//충돌체를 만들어서 관리


};

