#pragma once
class CPathManager
{

	SINGLETON(CPathManager);
	const static int MAXSIZE_PATH = 255;
private:
	WCHAR m_szContentPath[MAXSIZE_PATH];		//리소스 경로를 저장하는 배열

public:
	void init();

	const wchar_t* GetContentPath();
	const wchar_t* GetRelativeContentPath();
};

