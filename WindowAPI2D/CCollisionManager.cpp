#include "framework.h"
#include "CCollisionManager.h"
#include "SCene.h"
#include "CGameObject.h"
#include "CCollider.h"

CCollisionManager::CCollisionManager()
{
	m_arrCheck[0] = 0;
}

CCollisionManager::~CCollisionManager()
{

}

void CCollisionManager::CollisionGroupUpdate(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
{
	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();		//현재장면에서 충돌 확인

	const vector<CGameObject*>& vecLeft = pCurScene->GetGroupObject(objLeft); //현재장면의 왼쪽오브젝트 를 모두 갖는 벡터 
	const vector<CGameObject*>& vecRight = pCurScene->GetGroupObject(objRight); //현재장면의 오른쪽오브젝트 를 모두 갖는 벡터 
	
	for (int i = 0; i < vecLeft.size(); i++)
	{
		//충돌체 컴포넌트가 없는 경우 무시
		if (nullptr == vecLeft[i]->GetCollider())
			continue;
		for (int j = 0; j < vecRight.size(); j++)	//오른쪽 오브젝트 만큼 반복
		{	
			//충돌체 컴포넌트가 없는 경우 무시
			if (nullptr == vecRight[j]->GetCollider())
				continue;
			//자기자신과의 충돌 무시
			if (vecLeft[i] == vecRight[j])	//(i == j && Left == Right)
				continue;
			
			// 두 충돌체의 ID를 이용해서, 유일한 키 생성
			COLLIDER_ID id;
			id.left_id = vecLeft[i]->GetCollider()->Getid();
			id.Right_id = vecRight[j]->GetCollider()->Getid();
			
			map<ULONGLONG, bool>::iterator iter = m_mapCollInfo.find(id.ID);

			// 충돌 정보가 없는 경우,(처음으로 충돌하는 경우) 충돌하지 않은 상태를 넣어줌
			if (m_mapCollInfo.end() == iter)
			{
				m_mapCollInfo.insert(make_pair(id.ID, false));
				iter = m_mapCollInfo.find(id.ID);
			}
			
			//충돌 처리
			if (IsCollision(vecLeft[i]->GetCollider(), vecRight[j]->GetCollider())) //충돌을 했느냐
			{
				//첫번째는 고유키값 두번째가 true | false
				//prev 0,cur 0 이전 프레임에 충돌 했는지 안했는지 
				if (iter->second)
				{
					//이전과 현재 충돌 - 충돌중 vecleft[i]-충돌중, vecright[j]-충돌중
				
					vecLeft[i]->GetCollider()->OnCollision(vecRight[j]->GetCollider());
					vecRight[j]->GetCollider()->OnCollision(vecLeft[i]->GetCollider());
					iter->second = true;
				}
				//prev x,cur 0
				else
				{
					//이전 충돌 안함, 지금 충돌(현재) - 충돌 진입
					
					vecLeft[i]->GetCollider()->OnCollisionEnter(vecRight[j]->GetCollider());
					vecRight[j]->GetCollider()->OnCollisionEnter(vecLeft[i]->GetCollider());
					iter->second = true;
				}
			}
			else//충돌안함
			{	//prev 0, cur x
				if (iter->second)
				{
					// 이전에 충돌 지금 충돌 안함 - 충돌 해제
					
					vecLeft[i]->GetCollider()->OnCollisionExit(vecRight[j]->GetCollider());
					vecRight[j]->GetCollider()->OnCollisionExit(vecLeft[i]->GetCollider());
					iter->second = false;
				}
				//prev x, cur x
				else
				{
					//충돌 안해 *경축* 아무것도 안함
					iter->second = false;
				}
			}
		}
	}
}

bool CCollisionManager::IsCollision(CCollider* pLeftColl, CCollider* pRightColl) //충돌 여부를 확인하는함수 (현재 충돌중이다)
{
	//두 사각형의 중심에서 부터 끝까지의 거리를 더한값을 기준으로 거리가 크면 충돌x 거리가 작으면 충돌 o
	//사각충돌
	fPoint fptLeftPos = pLeftColl->GetFinalPos();
	fPoint fptLeftScale = pLeftColl->GetScale();
	
	fPoint fptRightPos = pRightColl->GetFinalPos();
	fPoint fptRightScale = pRightColl->GetScale();

	if (abs((fptLeftPos.x-fptRightPos.x)<(fptLeftPos.x+fptRightPos.x)/2.f)
		&& abs(fptLeftPos.y - fptRightPos.y) < (fptLeftPos.y + fptRightPos.y) / 2.f) 
	{
		return true;
	}

	return false;
}

void CCollisionManager::init()
{

}

void CCollisionManager::UPdate()
{
	for (int iRow = 0; iRow < (UINT)GROUP_GAMEOBJ::SIZE; iRow++)
	{
		for (int iCol = iRow; iCol < (UINT)GROUP_GAMEOBJ::SIZE; iCol++)	//전부다 볼 필요 없이 위에서 본것은 패스
		{
			if (m_arrCheck[iRow] & (1 << iCol));	//해당 비트가 1인경우 해당 그룹 검사
			{
				// 충돌을 검사하는 두그룹
				CollisionGroupUpdate((GROUP_GAMEOBJ)iRow, (GROUP_GAMEOBJ)iCol);	
			}
		}
	}
}

void CCollisionManager::CheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
{
	//[행][렬]
	UINT iRow;	//행
	UINT iCol;	//렬

	//더 작은 수를 행으로 둠
	if ((UINT)objLeft < (UINT)objRight)
	{
		iRow = (UINT)objLeft;
		iCol = (UINT)objRight;
	}
	else
	{
		iRow = (UINT)objRight;
		iCol = (UINT)objLeft;

	}
	
	m_arrCheck[iRow] |= (1 << iCol);

}

void CCollisionManager::UnCheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
{
	//[행][렬]
	UINT iRow;	//행
	UINT iCol;	//렬

	//더 작은 수를 행으로 둠
	if ((UINT)objLeft > (UINT)objRight)
	{
		iRow = (UINT)objLeft;
		iCol = (UINT)objRight;
	}
	else
	{
		iRow = (UINT)objRight;
		iCol = (UINT)objLeft;

	}
	
	m_arrCheck[iRow] &= ~(1 << iCol);

}

void CCollisionManager::Reset()
{
	
	memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_GAMEOBJ::SIZE);
	//전부다 0으로 만들때 처리속도가 빠름 memset
	
	//for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	//{
	//	m_arrCheck[i] = 0;
	//}
}
