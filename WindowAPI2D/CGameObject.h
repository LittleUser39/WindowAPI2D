#pragma once

class CCollider;

class CGameObject
{
	friend CEventManager;

private:
	wstring m_strName;				// �̸�
	fPoint m_fptPos;				// ��ġ
	fPoint m_fptScale;				// ũ��

	CCollider* m_pCollider;			// �浹ü

	bool m_bAlive;					//�ش� ������Ʈ�� ����ֳ�
	void SetDead();					//�ش� ������Ʈ �׾��� ����

public:
	CGameObject();
	virtual ~CGameObject();

	void SetPos(fPoint pos);		//��ġ ����
	void SetScale(fPoint scale);	//ũ�� ����
	void SetName(wstring name);		//�̸� ����

	fPoint GetPos();				//��ġ ��������
	fPoint GetScale();				//ũ�� ��������
	wstring GetName();				//�̸� ��������

	bool isDead();					//����Ȯ��

	virtual void Update() = 0;			//���� �����Լ� ��ӹ޾����� ������ �ؾ���
	virtual void finalUpdate() final;	
	virtual void Render(HDC hDC);		//�׸���
	virtual void component_render(HDC hDC);		//������Ʈ �׸���

	CCollider* GetCollider();					//�浹ü ��������
	void CreateCollider();						//�浹ü �����

	//�浹ó��
	virtual void OnCollision(CCollider* _pOther) {}			
	virtual void OnCollisionEnter(CCollider* _pOther) {}	
	virtual void OnCollisionExit(CCollider* _pOther) {}		
};
