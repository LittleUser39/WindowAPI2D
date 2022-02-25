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
	GetCurrentDirectory(MAXSIZE_PATH, m_szContentPath);  //프로그램 경로를 확인하는 함수(현재경로가져오기)
}
