#pragma once
class CCameraManager
{
	SINGLETON(CCameraManager);

private:
	fPoint m_fptLookAt;	//보고 있는 위치
	fPoint m_fptCurLookAt;	//카메라가 현제 보는 위치
	fPoint m_fptPrevLookAt;	//카메라가 이전에 보던위치
	CGameObject* m_pTargetobj; //트래킹 추적할 게임 오브젝트

	fPoint m_fptDiff;			//실제 보고 있는 위치랑 얼마나 보정해야 하는가 차이 변수
	
	float m_fTime;				//목적지를 따라가는 시간
	float m_fAccTime;			//목적지를 따라가는 소요시간
	float m_fSpeed;				//목적지를 따라가는 속력
	float m_fPreSpeed;			//목적지를 따라가는 이전속력
	float m_fAccel;				//목적지를 따라가는 가속도
	float m_fAccDir;			//가속도의 증가폭


	void CalDiff();
public:

	void Update();

	void SetLookAt(fPoint lookat);	//보고 있는 위치 설정
	void SetTargetobj(CGameObject* target);

	fPoint GetLookAt();
	fPoint GetRenderPos(fPoint objpos);	//카메라가 보고있는 대로 오브젝트가 그려져야함
	fPoint GetRealPos(fPoint renderpos);	//그려주는 곳 실제 좌표 반환

	
};

