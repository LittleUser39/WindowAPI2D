#pragma once
class CCameraManager
{
	SINGLETON(CCameraManager);

private:
	fPoint m_fptLookAt;	//보고 있는 위치
	CGameObject* m_pTargetobj; //트래킹 추적할 게임 오브젝트

	fPoint m_fptDiff;			//실제 보고 있는 위치랑 얼마나 보정해야 하는가 차이 변수
public:

	void Update();

	void SetLookAt(fPoint lookat);	//보고 있는 위치 설정
	void SetTargetobj(CGameObject* target);

	fPoint GetRenderPos(fPoint objpos);	//카메라가 보고있는 대로 오브젝트가 그려져야함

	void CalDiff();
};

