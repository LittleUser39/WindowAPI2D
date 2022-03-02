#pragma once

class CCollider;

union  COLLIDER_ID
{
	struct 
	{
		UINT left_id;
		UINT Right_id;
	};
	ULONGLONG ID; //left id(��),right(��) 
};

class CCollisionManager //��ü�� �浹��Ȳ�� ������Ʈ
{
	SINGLETON(CCollisionManager);
	

private:
	UINT m_arrCheck[(UINT)GROUP_GAMEOBJ::SIZE]; //�浹�ؾ��ϴ� �׷���� ���� �迭 - ��Ʈ�� �ؼ� ����� ������ ����
	map<ULONGLONG, bool> m_mapCollInfo;	// �浹ü ���� ���� update �浹 ���� 


	void CollisionGroupUpdate(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight);
	bool IsCollision(CCollider* pLeftColl, CCollider* pRightColl);		//�浹 ���θ� Ȯ���ϴ��Լ�
public:
	void init();		//�ʱ�ȭ
	void UPdate();		//�浹 Ȯ��
	
	void CheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight); //�׷찣�� �浹 ����
	void UnCheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight);
	void Reset();
};

