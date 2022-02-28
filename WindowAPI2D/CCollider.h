#pragma once
class CGameObject;

class CCollider
{
	friend class CGameObject;

private:
	static UINT s_iID; //������ ������ id��

	CGameObject* m_pOwner;
	fPoint m_fptOffsetPos;
	fPoint m_fptFinalPos;
	fPoint m_fptScale;

	UINT m_iID;		//�浹ü�� ������ id ��
public:
	CCollider();
	CCollider(const CCollider& other);
	~CCollider();

	CCollider& operator=(CCollider& other) = delete; //�Լ��� ����Ҽ� ���� ����

	fPoint GetOffsetPos();
	fPoint GetFinalPos();
	fPoint GetScale();
	UINT Getid();

	fPoint SetOffsetPos(fPoint offset);
	fPoint SetFinalPos(fPoint pos);
	fPoint SetScale(fPoint scale);

	void finalUpdate();
	void Render(HDC hDc);

	//�浹 ���� �Լ�
	void OnCollision(CCollider* pOther);
	void OnCollisionEnter(CCollider* pOther);
	void OnCollisionExit(CCollider* pOther);
};

