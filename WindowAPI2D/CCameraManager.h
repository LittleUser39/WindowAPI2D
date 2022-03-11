#pragma once
class CGameObject;
class CTexture;

enum class CAM_EFFECT
{
	FADE_IN,
	FADE_OUT,


	NONE,
};
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

	CAM_EFFECT m_eEffect;
	CTexture* m_pTex;
	float m_fEffectDuration;
	float m_fCurTime;

	void CalDiff();
public:
	void init();
	void Update();
	void Render(HDC hDc);

	void SetLookAt(fPoint lookat);			//���� �ִ� ��ġ ����
	void SetTargetobj(CGameObject* target);	// Ÿ�ٱ������� ����
	void Scroll(fVec2 vec, float velocity);	//�����Ѽӵ��� ���� (�����̱�)

	void FadeIn(float duration);
	void FadeOut(float duration);

	fPoint GetLookAt();
	fPoint GetRenderPos(fPoint objpos);	//ī�޶� �����ִ� ��� ������Ʈ�� �׷�������
	fPoint GetRealPos(fPoint renderpos);	//�׷��ִ� �� ���� ��ǥ ��ȯ

};

