#include "framework.h"
#include "CResourceManager.h"
#include "CTexture.h"
#include "CSound.h"
CResourceManager::CResourceManager()
{
	m_mapTex = {};
}

CResourceManager::~CResourceManager()	//생성된 리소스를 정리 - map안에 리소스를 넣어서 이터로 전체를 찾고 
{
	for (map<wstring, CTexture*>::iterator iter = m_mapTex.begin(); iter != m_mapTex.end(); iter++)
	{
		if (nullptr != iter->second)
			delete iter->second;
	}
	m_mapTex.clear();
	
	for (map<wstring, CSound*>::iterator iter = m_mapSound.begin(); iter != m_mapSound.end(); iter++)
	{
		if (nullptr != iter->second)
			delete iter->second;

	}
	m_mapSound.clear();
}

CTexture* CResourceManager::FindTexture(const wstring& strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(strKey);

	if(m_mapTex.end()==iter)
		return nullptr;
	else
	{
		return iter->second;
	}
}

CTexture* CResourceManager::LoadTexture(const wstring& strKey, const wstring& strPath)
{
	//이미 있던거면 있던것을 반환
	CTexture* pTex = FindTexture(strKey);
	if (nullptr != pTex)
		return pTex;
	//없던거면 추가

	wstring strFilePath = CPathManager::getInst()->GetContentPath();
	strFilePath += strPath;

	pTex = new CTexture();
	pTex->Load(strFilePath);
	pTex->SetKey(strKey);		//그 키로 관리하기 때문에 그것으로 세팅
	pTex->SetPath(strPath);		//그 곳의 경로로 세팅

	m_mapTex.insert(make_pair(strKey, pTex));	//맵에 두가지 값을 입력한다. 하나는 비교를 위한 키값 , 하나는 진짜 데이터
	

	return pTex;
}

CSound* CResourceManager::FindSound(const wstring& strkey)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(strkey);

	if (m_mapSound.end() == iter)
		return nullptr;
	else
	{
		return iter->second;
	}
}

CSound* CResourceManager::LoadSound(const wstring& strkey, const wstring& strRelativePath)
{
	// Sound를 불러오기 전 자료구조에 이미 Sound가 있는지 확인
	CSound* pSound = FindSound(strkey);
	if (nullptr != pSound)
	{
		return pSound;
	}

	// Sound 저장 경로 확인
	wstring strFilePath = CPathManager::getInst()->GetRelativeContentPath();
	strFilePath += strRelativePath;

	// Sound 생성 후 저장
	pSound = new CSound;
	pSound->Load(strFilePath);
	pSound->SetKey(strkey);
	pSound->SetPath(strRelativePath);

	m_mapSound.insert(make_pair(strkey, pSound));

	return pSound;
}
