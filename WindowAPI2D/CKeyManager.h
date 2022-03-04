#pragma once
class CKeyManager
{
	SINGLETON(CKeyManager);

private:
	static const int VKEY_SIZE = 0xFF;	//VK의 최대 갯수(이미 키들의 값이 정해져 있어서 그값을 사용)
	bool m_arrPrevKey[VKEY_SIZE];		//이전 키의 입력상태를 저장할 배열
	bool m_arrCurKey[VKEY_SIZE];		//현재 키의 입력상태를 저장할 배열

	fPoint m_fptCurMousePos;			//현재 마우스 좌표입력 변수

public:
	void Update();
	void Init();

	bool GetButton(const int key);	//키가 눌러진 상태 true
	bool GetButtonDown(const int key); //키가 눌러진 순간만 true
	bool GetButtonUp(const int key);   //키가 올라간 순간만 true

	fPoint GetMousePos();				//마우스 좌표 받기
};

