#pragma once

class CCollider;

class CGameObject
{
	friend CEventManager;

private:
	wstring m_strName;							// 이름
	fPoint m_fptPos;							// 위치
	fPoint m_fptScale;							// 크기

	CCollider* m_pCollider;						// 충돌체

	bool m_bAlive;								//해당 오브젝트가 살아있나
	void SetDead();								//해당 오브젝트 죽었다 설정

public:
	CGameObject();
	CGameObject(const CGameObject& other);
	virtual ~CGameObject();
	virtual CGameObject* Clone() = 0;			//포인터 변수로 생성하기 위해 만듬

	void SetPos(fPoint pos);					//위치 설정
	void SetScale(fPoint scale);				//크기 설정
	void SetName(wstring name);					//이름 설정

	fPoint GetPos();							//위치 가져오기
	fPoint GetScale();							//크기 가져오기
	wstring GetName();							//이름 가져오기

	bool isDead();								//생존확인

	virtual void Update() = 0;					//순수 가상함수 상속받았으면 무조건 해야함
	virtual void finalUpdate() final;	
	virtual void Render(HDC hDC);				//그리기
	virtual void component_render(HDC hDC);		//컴포넌트 그리기

	CCollider* GetCollider();					//충돌체 가져오기
	void CreateCollider();						//충돌체 만들기

	//충돌처리
	virtual void OnCollision(CCollider* _pOther) {}			
	virtual void OnCollisionEnter(CCollider* _pOther) {}	
	virtual void OnCollisionExit(CCollider* _pOther) {}		
};
