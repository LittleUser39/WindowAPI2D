#pragma once

class CScene;


class CSceneManager
{
	SINGLETON(CSceneManager);
	
	friend class CEventManager;

private:
	CScene* m_arrScene[(int)GROUP_SCENE::SIZE]; //���(scene)�� ������ �迭
	CScene* m_pCurScene;						//���� ����� ����Ű�� ����
	
	void ChangeScene(GROUP_SCENE type);	//��� �����ϴ� �Լ�

public:
	void Init();						//����� ���������� �ʱ�ȭ �Լ�(�ܰ�)
	void Render(HDC hDc);				//����� �׷��� - ���� �����ִ� �͸� �׷���
	void Update();						//���� ��鸸 ������Ʈ - ���� �����ִ� �͸� ������Ʈ
	

	CScene* GetCurScene();				//���� ����� ��ȯ (�׷��� cscene*�� ��ȯ)
};

