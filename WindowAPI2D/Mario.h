#pragma once
#include "CGameObject.h"
class CTexture;
class Mario : public CGameObject
{
	float m_dVelocity;	//�׳� �ӵ�
	float m_UpSpeed;	//���� �ӵ�
	float m_gravite;	//�߷�

	CTexture* m_pTex;	//�̹��� ����

	bool Isfly;			//ĳ���Ͱ� �ϴÿ� �ִ���
	bool IsRight;		//������ȯ

public:
	Mario();
	virtual ~Mario();

	virtual Mario* Clone();

	virtual void Update();
	virtual void Render(HDC hDc);

	void CreateMissile(); // �̻����� ����� �Լ�

	//�浹 ���� �Լ�
	virtual void OnCollision(CCollider* pOther);
	virtual void OnCollisionEnter(CCollider* pOther);
	virtual void OnCollisionExit(CCollider* pOther);
};

