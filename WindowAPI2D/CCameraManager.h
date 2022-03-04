#pragma once
class CCameraManager
{
	SINGLETON(CCameraManager);

private:
	fPoint m_fptLookAt;	//���� �ִ� ��ġ
	fPoint m_fptCurLookAt;	//ī�޶� ���� ���� ��ġ
	fPoint m_fptPrevLookAt;	//ī�޶� ������ ������ġ
	CGameObject* m_pTargetobj; //Ʈ��ŷ ������ ���� ������Ʈ

	fPoint m_fptDiff;			//���� ���� �ִ� ��ġ�� �󸶳� �����ؾ� �ϴ°� ���� ����
	
	float m_fTime;				//�������� ���󰡴� �ð�
	float m_fAccTime;			//�������� ���󰡴� �ҿ�ð�
	float m_fSpeed;				//�������� ���󰡴� �ӷ�
	float m_fPreSpeed;			//�������� ���󰡴� �����ӷ�
	float m_fAccel;				//�������� ���󰡴� ���ӵ�
	float m_fAccDir;			//���ӵ��� ������


	void CalDiff();
public:

	void Update();

	void SetLookAt(fPoint lookat);	//���� �ִ� ��ġ ����
	void SetTargetobj(CGameObject* target);

	fPoint GetLookAt();
	fPoint GetRenderPos(fPoint objpos);	//ī�޶� �����ִ� ��� ������Ʈ�� �׷�������
	fPoint GetRealPos(fPoint renderpos);	//�׷��ִ� �� ���� ��ǥ ��ȯ

	
};

