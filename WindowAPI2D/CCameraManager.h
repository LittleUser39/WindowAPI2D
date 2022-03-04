#pragma once
class CCameraManager
{
	SINGLETON(CCameraManager);

private:
	fPoint m_fptLookAt;	//���� �ִ� ��ġ
	CGameObject* m_pTargetobj; //Ʈ��ŷ ������ ���� ������Ʈ

public:

	void SetLookAt(fPoint lookat);	//���� �ִ� ��ġ ����
	void SetTargetobj(CGameObject* target);

};

