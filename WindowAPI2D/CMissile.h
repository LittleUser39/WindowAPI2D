#pragma once
#include "CGameObject.h"
class CMissile : public CGameObject
{
private:
	fVec2 m_fvDir;
	float m_fVelocity;	//�̻��� �ӵ�
	
public:
	CMissile();
	~CMissile();

	virtual void Update();
	
	void SetDir(fVec2 vec);	//����	����
	fVec2 GetDir();			//���� ��ȯ
};

