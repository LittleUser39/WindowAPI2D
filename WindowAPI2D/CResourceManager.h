#pragma once

class CTexture;

class CResourceManager
{
	SINGLETON(CResourceManager);

private:
	map<wstring, CTexture*> m_mapTex;	//이진탐색트리 (자가균형) 비교를 위한 키값과 저장을 위한 텍스트값 (데이터값)을 가지고 있음  

public:
	
	CTexture* FindTexture(const wstring& strKey); //텍스쳐 찾기
	CTexture* LoadTexture(const wstring& strKey, const wstring& strPath); //텍스쳐 로드
};

