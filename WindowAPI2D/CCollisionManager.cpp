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
	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();		//������鿡�� �浹 Ȯ��

	const vector<CGameObject*>& vecLeft = pCurScene->GetGroupObject(objLeft); //��������� ���ʿ�����Ʈ �� ��� ���� ���� 
	const vector<CGameObject*>& vecRight = pCurScene->GetGroupObject(objRight); //��������� �����ʿ�����Ʈ �� ��� ���� ���� 
	
	for (int i = 0; i < vecLeft.size(); i++)
	{
		//�浹ü ������Ʈ�� ���� ��� ����
		if (nullptr == vecLeft[i]->GetCollider())
			continue;
		for (int j = 0; j < vecRight.size(); j++)	//������ ������Ʈ ��ŭ �ݺ�
		{	
			//�浹ü ������Ʈ�� ���� ��� ����
			if (nullptr == vecRight[j]->GetCollider())
				continue;
			//�ڱ��ڽŰ��� �浹 ����
			if (vecLeft[i] == vecRight[j])	//(i == j && Left == Right)
				continue;
			
			// �� �浹ü�� ID�� �̿��ؼ�, ������ Ű ����
			COLLIDER_ID id;
			id.left_id = vecLeft[i]->GetCollider()->Getid();
			id.Right_id = vecRight[j]->GetCollider()->Getid();
			
			map<ULONGLONG, bool>::iterator iter = m_mapCollInfo.find(id.ID);

			// �浹 ������ ���� ���,(ó������ �浹�ϴ� ���) �浹���� ���� ���¸� �־���
			if (m_mapCollInfo.end() == iter)
			{
				m_mapCollInfo.insert(make_pair(id.ID, false));
				iter = m_mapCollInfo.find(id.ID);
			}
			
			//�浹 ó��
			if (IsCollision(vecLeft[i]->GetCollider(), vecRight[j]->GetCollider())) //�浹�� �ߴ���
			{
				//ù��°�� ����Ű�� �ι�°�� true | false
				//prev 0,cur 0 ���� �����ӿ� �浹 �ߴ��� ���ߴ��� 
				if (iter->second)
				{
					//�浹ü �� �ϳ��� dead ���¶�� �浹 ����
					if (vecLeft[i]->isDead() || vecRight[j]->isDead())
					{
						vecLeft[i]->GetCollider()->OnCollisionExit(vecRight[j]->GetCollider());
						vecRight[j]->GetCollider()->OnCollisionExit(vecLeft[i]->GetCollider());
						iter->second = false;
					}
					else
					{
						//������ ���� �浹 - �浹�� vecleft[i]-�浹��, vecright[j]-�浹��
						vecLeft[i]->GetCollider()->OnCollision(vecRight[j]->GetCollider());
						vecRight[j]->GetCollider()->OnCollision(vecLeft[i]->GetCollider());
						iter->second = true;

					}
				}
				//prev x,cur 0
				else
				{	
					//�浹ü �� �ϳ��� dead ���¶�� �浹 ��Ű�� ����
					if (vecLeft[i]->isDead() || vecRight[j]->isDead())
					{
							//�ƹ��͵� ��������
						iter->second = false;
					}
					else
					{
						//���� �浹 ����, ���� �浹(����) - �浹 ����
						vecLeft[i]->GetCollider()->OnCollisionEnter(vecRight[j]->GetCollider());
						vecRight[j]->GetCollider()->OnCollisionEnter(vecLeft[i]->GetCollider());
						iter->second = true;

					}
				}
			}
			else
			{	
				//�浹����
				//prev 0, cur x
				if (iter->second)
				{
					// ������ �浹 ���� �浹 ���� - �浹 ����
					
					vecLeft[i]->GetCollider()->OnCollisionExit(vecRight[j]->GetCollider());
					vecRight[j]->GetCollider()->OnCollisionExit(vecLeft[i]->GetCollider());
					iter->second = false;
				}
				//prev x, cur x
				else
				{
					//�浹 ���� *����* �ƹ��͵� ����
					iter->second = false;
				}
			}
		}
	}
}

bool CCollisionManager::IsCollision(CCollider* pLeftColl, CCollider* pRightColl) //�浹 ���θ� Ȯ���ϴ��Լ� (���� �浹���̴�)
{
	//�� �簢���� �߽ɿ��� ���� �������� �Ÿ��� ���Ѱ��� �������� �Ÿ��� ũ�� �浹x �Ÿ��� ������ �浹 o
	//�簢�浹
	fPoint fptLeftPos = pLeftColl->GetFinalPos();
	fPoint fptLeftScale = pLeftColl->GetScale();
	
	fPoint fptRightPos = pRightColl->GetFinalPos();
	fPoint fptRightScale = pRightColl->GetScale();

	if (abs(fptLeftPos.x - fptRightPos.x) < (fptLeftScale.x + fptRightScale.x)/2.f	//�̰� scale�� pos�� �ؼ� ���������� ���� �ذ���
		&& abs(fptLeftPos.y - fptRightPos.y) < (fptLeftScale.y + fptRightScale.y) / 2.f) 
	{
		return true;
	}

	return false;
}

void CCollisionManager::init()
{

}

void CCollisionManager::Update()
{
	for (UINT iRow = 0; iRow < (UINT)GROUP_GAMEOBJ::SIZE; iRow++)
	{
		for (UINT iCol = iRow; iCol < (UINT)GROUP_GAMEOBJ::SIZE; iCol++)
		{
			if (m_arrCheck[iRow] & (1 << iCol))
			{
				// �浹�� �˻��ؾ��ϴ� �� �׷�
				CollisionGroupUpdate((GROUP_GAMEOBJ)iRow, (GROUP_GAMEOBJ)iCol);
			}
		}
	}
}

void CCollisionManager::CheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
{
	//[��][��]
	UINT iRow;	//��
	UINT iCol;	//��

	//�� ���� ���� ������ ��
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
	//[��][��]
	UINT iRow;	//��
	UINT iCol;	//��

	//�� ���� ���� ������ ��
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
	
	m_arrCheck[iRow] &= ~(1 << iCol);

}

void CCollisionManager::Reset()
{
	
	memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_GAMEOBJ::SIZE);
	//���δ� 0���� ���鶧 ó���ӵ��� ���� memset
	
	//for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	//{
	//	m_arrCheck[i] = 0;
	//}
}
