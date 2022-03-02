#pragma once
//�Լ��� ���� ����� ��忡�� ���� ��ȯ �Ǵ��� Ȯ���Ҽ� �ִ�.

class CCollider;

class CGameObject
{
	friend class CEventManager;
private:
	wstring m_strName;
	fPoint m_fptPos;			//��ġ ��
	fPoint m_fptScale;			//ũ�� ��

	bool m_bAllive;				//����ִ� ����
	void SetDead();				//���� ���·� �����

	CCollider* m_pCollider;	//�浹ü�� ������ �ּҸ� ������ nullptr

public:
	CGameObject();
	virtual ~CGameObject();	//virtual �ϴ� ���� �θ� �Ҹ��� ���� �ڽ� �Ҹ��ڸ� ����ϱ� ����

	virtual void Update() = 0;	//�����Լ� - ��ӹ��� �ְ� �������̵��ؼ� �Լ� �̿� 
	virtual void finalUpdate()	final;	//��ӹ��� Ŭ������ ���̻� �������̵� �ϴ°��� �����ִ� Ű����
	virtual void Render(HDC hDc) ; //�̰� ������Ʈ���� �׸��� �Լ� (�Ű����� DC)
	virtual void component_render(HDC hDc);

	void SetPos(fPoint pos);		//�ش� ��ġ�� ����
	void SetScale(fPoint scale);	//�ش� ũ��� ����
	
	void SetName(wstring name);
	wstring GetName();
	
	fPoint GetPos();				//�ش� ��ġ ������
	fPoint GetScale();				//�ش� ũ�� ������
	CCollider* GetCollider();		//������ �ִ� �浹ü �־���
	void CreateCollider();			//�浹ü�� ���� ����
	bool isDead();		//���� ���� Ȯ��

	//�浹 ���� �Լ�
	virtual void OnCollision(CCollider* pOther){};
	virtual void OnCollisionEnter(CCollider* pOther){};
	virtual void OnCollisionExit(CCollider* pOther){};

};

