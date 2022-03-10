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
	//���:(���� �ַ�� ���)\output\debug
	//���:(���� �ַ�� ���)\output\relese
	GetCurrentDirectory(MAXSIZE_PATH, m_szContentPath);  //���α׷� ��θ� Ȯ���ϴ� �Լ�(�����ΰ�������)
	int size = wcslen(m_szContentPath);
	//������ ��ŭ �ݺ�
	for (int i = size - 1; i >= 0; i--)
	{
		//\\�� ã��(���� ���� ���丮(����))
		if ('\\' == m_szContentPath[i])
		{
			m_szContentPath[i] = '\0';
			break;
		}
	}
	//���: (���� �ַ�ǰ��) \\output
	wcscat_s(m_szContentPath, MAXSIZE_PATH, L"\\Release\\content");
	Logger::info(m_szContentPath);
}

const wchar_t* CPathManager::GetContentPath()
{
	return	m_szContentPath;
}

const wchar_t* CPathManager::GetRelativeContentPath()
{
	return L"..\\Release\\content\\";
}
