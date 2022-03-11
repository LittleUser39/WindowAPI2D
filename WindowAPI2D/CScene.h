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
	
	UINT m_iTileX;
	UINT m_iTileY;

public:
	CScene();
	virtual ~CScene();

	virtual void Update();
	virtual void finalUpdate();
	virtual void Render(HDC hDc);
	void Render_Tile(HDC hDc);
	//
	virtual void Enter() = 0;	//��鿡 ���� - ��鸶�� �޶� �������̵��ؼ� ��� 
	virtual void Exit()  = 0;	//��鿡�� ������ - ���� �����Լ� �ڽ��� ������ ��������

	const vector<CGameObject*>& GetGroupObject(GROUP_GAMEOBJ group);
	vector<CGameObject*>& GetUIGroup();		// UI�� ������ ������ �����ؾ� �ϱ� ������ ������ ���� / ���� �ʿ�!
	
	void SetName(const wstring& strName);	//�̸� ����
	wstring GetName();						//�̸� ��������
	
	UINT GetTileX();
	UINT GetTileY();

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type); // ���� ������Ʈ �߰� (������Ʈ,������Ʈ�� � �׷쿡 ���ϴ°�)

	void DeleteGroup(GROUP_GAMEOBJ group);		//�ش� �׷츸 ������
	void DeleteAll();							//�� ��鿡 �ִ� ������Ʈ�� ����
	
	void CreateTile(UINT xsize, UINT ysize);
	void LoadTile(const wstring& strPath);
};

