#pragma once

//전방 선언: 해당 클래스의 포인터 변수를 사용할 수 있게 해줌.
//해더 파일이 여러번 호출되어 #pramaonce 선언부를 확인 불가한 문제 해결
//컴파일 속도를 줄임.
class CGameObject;


class CScene
{
private:
	vector<CGameObject*> m_arrObj[(int)GROUP_GAMEOBJ::SIZE];
	wstring m_strName;
	
	
public:
	CScene();
	virtual ~CScene();

	virtual void Update();
	virtual void finalUpdate();
	virtual void Render(HDC hDc);

	//
	virtual void Enter() = 0;	//장면에 들어갈때 - 장면마다 달라서 오버라이딩해서 사용 
	virtual void Exit()  = 0;	//장면에서 나갈때 - 순수 가상함수 자식이 무조건 만들어야함

	const vector<CGameObject*>& GetGroupObject(GROUP_GAMEOBJ group);

	void SetName(const wstring& strName);	//이름 설정
	wstring GetName();						//이름 가져오기

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type); // 씬에 오브젝트 추가 (오브젝트,오브젝트가 어떤 그룹에 속하는가)
protected:
	void ClearObject();		//그 장면에 있던 오브젝트들 삭제
};

