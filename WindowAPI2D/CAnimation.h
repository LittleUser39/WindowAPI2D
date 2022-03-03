#pragma once

class CAnimator;
class CTexture;

struct tAniFrm
{
	fPoint fptLT;				//���� ������
	fPoint fptSlice;			//�󸶳� �߷����ֳ�
	float fDuration;			//���ʵ��� ��������
};

class CAnimation
{
	friend class CAnimator;

private:
	wstring			m_strName;			//�ִϸ��̼� �̸�
	CAnimator*		m_pAnimator;		//�ִϸ�����
	CTexture*		m_pTex;				//���ϸ��̼� �̹���
	vector<tAniFrm> m_vecFrm;			//��� �������� �ڸ��� ���� �� �����ð� ���� ����
	int				m_iCurFrm;			//���� �������� index
	float			m_fAccTime;			//���� �������� �����ð�

public:
	CAnimation();
	~CAnimation();

	void SetName(const wstring& strName);	//�̸� ����
	const wstring& GetName();				//�̸� �������� string�� ������ ������ const��
	
	void Update();							//���� ����� ���ʵ��� �׷����ϳ�
	void Render(HDC hDc);
	void Create(CTexture* pTex, fPoint lt, fPoint slice, fPoint step, float duration, UINT frmcount); //�ִϸ��̼� ����
};

