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
	//경로:(게임 솔루션 경로)\output\debug
	//경로:(게임 솔루션 경로)\output\relese
	GetCurrentDirectory(MAXSIZE_PATH, m_szContentPath);  //프로그램 경로를 확인하는 함수(현재경로가져오기)
	int size = wcslen(m_szContentPath);
	//사이즈 만큼 반복
	for (int i = size - 1; i >= 0; i--)
	{
		//\\를 찾음(제일 뒤의 디렉토리(폴더))
		if ('\\' == m_szContentPath[i])
		{
			m_szContentPath[i] = '\0';
			break;
		}
	}
	//경로: (게임 솔루션경로) \\output
	wcscat_s(m_szContentPath, MAXSIZE_PATH, L"\\Release\\content");
	Logger::info(m_szContentPath);
}

const wchar_t* CPathManager::GetContentPath()
{
	return	m_szContentPath;
}
