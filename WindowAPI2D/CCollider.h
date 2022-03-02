#pragma once
class CGameObject;

class CCollider
{
	friend class CGameObject;

private:
	static UINT s_iID; //데이터 영역의 id값

	CGameObject* m_pOwner;
	fPoint m_fptOffsetPos;
	fPoint m_fptFinalPos;
	fPoint m_fptScale;
	bool m_bIsCollsing;
	int m_iCollCount; //충돌 중인 갯수;


	UINT m_iID;		//충돌체의 고유한 id 값
public:
	CCollider();
	CCollider(const CCollider& other);
	~CCollider();

	CCollider& operator=(CCollider& other) = delete; //함수를 사용할수 없게 막음

	fPoint GetOffsetPos();
	fPoint GetFinalPos();
	fPoint GetScale();
	UINT Getid();

	fPoint SetOffsetPos(fPoint offset);
	fPoint SetFinalPos(fPoint pos);
	fPoint SetScale(fPoint scale);

	void finalUpdate();
	void Render(HDC hDc);

	//충돌 시점 함수
	virtual void OnCollision(CCollider* pOther);
	virtual void OnCollisionEnter(CCollider* pOther);
	virtual void OnCollisionExit(CCollider* pOther);
};

