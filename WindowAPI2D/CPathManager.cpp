#include "framework.h"
#include "CPathManager.h"

CPathManager::CPathManager()
{
	
}
CPathManager::~CPathManager()
{

}

void CPathManager::init()
{
	GetCurrentDirectory(MAXSIZE_PATH, m_szContentPath);  //���α׷� ��θ� Ȯ���ϴ� �Լ�(�����ΰ�������)
}
