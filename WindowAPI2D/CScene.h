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

	void Update();
	void Render(HDC hDc);

	void SetName(const wstring& strName);	//�̸� ����
	wstring GetName();						//�̸� ��������

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type); // ���� ������Ʈ �߰� 
};

