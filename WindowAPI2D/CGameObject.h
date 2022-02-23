#pragma once
//�Լ��� ���� ����� ��忡�� ���� ��ȯ �Ǵ��� Ȯ���Ҽ� �ִ�.
class CGameObject
{
private:
	fPoint m_fptPos;			//��ġ ��
	fPoint m_fptScale;			//ũ�� ��

public:
	CGameObject();
	virtual ~CGameObject();	//virtual �ϴ� ���� �θ� �Ҹ��� ���� �ڽ� �Ҹ��ڸ� ����ϱ� ����

	virtual void Update() = 0;	//�����Լ� - ��ӹ��� �ְ� �������̵��ؼ� �Լ� �̿� 
	virtual void Render(HDC hDc) ; //�̰� ������Ʈ���� �׸��� �Լ� (�Ű����� DC)

	void SetPos(fPoint pos);		//�ش� ��ġ�� ����
	void SetScale(fPoint scale);	//�ش� ũ��� ����

	fPoint GetPos();				//�ش� ��ġ ������
	fPoint GetScale();				//�ش� ũ�� ������
};

