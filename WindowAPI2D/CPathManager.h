#pragma once
class CPathManager
{

	SINGLETON(CPathManager);
	const static int MAXSIZE_PATH = 255;
private:
	WCHAR m_szContentPath[MAXSIZE_PATH];		//���ҽ� ��θ� �����ϴ� �迭

public:
	void init();

	const wchar_t* GetContentPath();
};

