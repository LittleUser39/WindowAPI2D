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

	virtual void Update() = 0;	//�����Լ� - ��ӹ��� �ְ� �������̵��ؼ� �Լ� �̿� 
	virtual void Render(HDC hDc) = 0;

	void SetPos(fPoint pos);		//�ش� ��ġ�� ����
	void SetScale(fPoint scale);	//�ش� ũ��� ����

	fPoint GetPos();				//�ش� ��ġ ������
	fPoint GetScale();				//�ش� ũ�� ������
};

