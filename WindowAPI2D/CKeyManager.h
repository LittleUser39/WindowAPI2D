#pragma once
class CKeyManager
{
	SINGLETON(CKeyManager);

private:
	static const int VKEY_SIZE = 0xFF;	//VK�� �ִ� ����(�̹� Ű���� ���� ������ �־ �װ��� ���)
	bool m_arrPrevKey[VKEY_SIZE];		//���� Ű�� �Է»��¸� ������ �迭
	bool m_arrCurKey[VKEY_SIZE];		//���� Ű�� �Է»��¸� ������ �迭

	fPoint m_fptCurMousePos;			//���� ���콺 ��ǥ�Է� ����

public:
	void Update();
	void Init();

	bool GetButton(const int key);	//Ű�� ������ ���� true
	bool GetButtonDown(const int key); //Ű�� ������ ������ true
	bool GetButtonUp(const int key);   //Ű�� �ö� ������ true

	fPoint GetMousePos();				//���콺 ��ǥ �ޱ�
};

