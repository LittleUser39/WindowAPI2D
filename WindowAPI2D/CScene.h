#pragma once

//전방 선언: 해당 클래스의 포인터 변수를 사용할 수 있게 해줌.
//해더 파일이 여러번 호출되어 #pramaonce 선언부를 확인 불가한 문제 해결
//컴파일 속도를 줄임.
class CGameObject;


class CScene
{
	vector<CGameObject*> m_arrObj[(int)GROUP_GAMEOBJ::SIZE];
	wstring m_strName;
	
	
public:
	CScene();
	~CScene();

	void Update();
	void Render(HDC hDc);

	void SetName(const wstring& strName);	//이름 설정
	wstring GetName();						//이름 가져오기

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ Obj); // 씬에 오브젝트 추가 
};

