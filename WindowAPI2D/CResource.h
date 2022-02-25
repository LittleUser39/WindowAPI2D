#pragma once
class CResource
{
private:
	wstring m_strKey;	//리소스 각자의 키값
	wstring m_strPath;	//외부의 경로를 불러옴

public:
	CResource();
	virtual ~CResource();

	void SetKey(const wstring& strKey); //크기가 크기때문에 원본을 가져올라고 레퍼런스로 받아줌
	void SetPath(const wstring& strPath);

	const wstring& GetKey();
	const wstring& GetPath();

};

