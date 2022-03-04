#pragma once
class CCameraManager
{
	SINGLETON(CCameraManager);

private:
	fPoint m_fptLookAt;	//보고 있는 위치
	CGameObject* m_pTargetobj; //트래킹 추적할 게임 오브젝트

public:

	void SetLookAt(fPoint lookat);	//보고 있는 위치 설정
	void SetTargetobj(CGameObject* target);

};

