#include "framework.h"
#include "CPathManager.h"

CPathManager::CPathManager()
{
	m_szContentPath[0] = {};
}
CPathManager::~CPathManager()
{

}

void CPathManager::init()
{
	GetCurrentDirectory(MAXSIZE_PATH, m_szContentPath);  //���α׷� ��θ� Ȯ���ϴ� �Լ�(�����ΰ�������)

	Logger::info(m_szContentPath);
}
