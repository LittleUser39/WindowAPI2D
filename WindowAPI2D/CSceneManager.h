#pragma once

class CScene;


class CSceneManager
{
	SINGLETON(CSceneManager);

private:
	CScene* m_arrScene[(int)GROUP_SCENE::SIZE]; //���(scene)�� ������ �迭
	CScene* m_pCurScene;						//���� ����� ����Ű�� ����
public:
	void ChangeScene(GROUP_SCENE type);
	void Init();	//����� ���������� �ʱ�ȭ �Լ�(�ܰ�)
	void Render(HDC hDc);	//����� �׷��� - ���� �����ִ� �͸� �׷���
	void Update();	//���� ��鸸 ������Ʈ - ���� �����ִ� �͸� ������Ʈ

};
//press space to start  start ���
//������ ���� �Ǵ� �������� 1 X������ ��

