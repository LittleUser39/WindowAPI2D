#pragma once

class CCollider;

//공용체: 내부에 구현된 변수들은 같은 시작주소를 같는다.
union  COLLIDER_ID
{
	struct 
	{
		UINT left_id;
		UINT Right_id;
	};
	ULONGLONG ID; //left id(앞),right(뒤) 
};

class CCollisionManager //전체의 충돌상황을 업데이트
{
	SINGLETON(CCollisionManager);
	

private:
	UINT m_arrCheck[(UINT)GROUP_GAMEOBJ::SIZE]; //충돌해야하는 그룹들을 가진 배열 - 비트로 해서 계산을 빠르게 만듬
	map<ULONGLONG, bool> m_mapCollInfo;			// 충돌체 간의 이전 충돌 정보 


	void CollisionGroupUpdate(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight);
	bool IsCollision(CCollider* pLeftColl, CCollider* pRightColl);		//충돌 여부를 확인하는함수
public:
	void init();		//초기화
	void Update();		//충돌 확인
	
	void CheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight); //그룹간의 충돌 설정
	void UnCheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight);
	void Reset();
};

