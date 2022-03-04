#pragma once
class CCameraManager
{
	SINGLETON(CCameraManager);

private:
	fPoint m_fptLookAt;	//���� �ִ� ��ġ
	CGameObject* m_pTargetobj; //Ʈ��ŷ ������ ���� ������Ʈ

	fPoint m_fptDiff;			//���� ���� �ִ� ��ġ�� �󸶳� �����ؾ� �ϴ°� ���� ����
public:

	void Update();

	void SetLookAt(fPoint lookat);	//���� �ִ� ��ġ ����
	void SetTargetobj(CGameObject* target);

	fPoint GetRenderPos(fPoint objpos);	//ī�޶� �����ִ� ��� ������Ʈ�� �׷�������

	void CalDiff();
};

