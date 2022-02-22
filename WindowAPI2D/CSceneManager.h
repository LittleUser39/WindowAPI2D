#pragma once

class CScene;


class CSceneManager
{
	SINGLETON(CSceneManager);

private:
	CScene* m_arrScene[(int)GROUP_SCENE::SIZE]; //장면(scene)을 저장할 배열
	CScene* m_pCurScene;						//현재 장면을 가르키는 변수
public:
	void ChangeScene(GROUP_SCENE type);
	void Init();	//장면이 생성했을때 초기화 함수(단계)
	void Render(HDC hDc);	//장면을 그려줌 - 현재 보고있는 것만 그려줌
	void Update();	//현재 장면만 업데이트 - 현재 보고있는 것만 업데이트

};
//press space to start  start 장면
//누르고 진행 되는 스테이지 1 X누르면 감

