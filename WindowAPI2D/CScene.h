#pragma once

//���� ����: �ش� Ŭ������ ������ ������ ����� �� �ְ� ����.
//�ش� ������ ������ ȣ��Ǿ� #pramaonce ����θ� Ȯ�� �Ұ��� ���� �ذ�
//������ �ӵ��� ����.
class CGameObject;


class CScene
{
private:
	vector<CGameObject*> m_arrObj[(int)GROUP_GAMEOBJ::SIZE];
	wstring m_strName;
	
	
public:
	CScene();
	~CScene();

	virtual void Update();
	virtual void Render(HDC hDc);

	virtual void Enter() = 0;	//��鿡 ���� - ��鸶�� �޶� �������̵��ؼ� ��� 
	virtual void Exit()  = 0;	//��鿡�� ������ - ���� �����Լ� �ڽ��� ������ ��������

	void SetName(const wstring& strName);	//�̸� ����
	wstring GetName();						//�̸� ��������

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type); // ���� ������Ʈ �߰� (������Ʈ,������Ʈ�� � �׷쿡 ���ϴ°�)
protected:
	void ClearObject();
};

