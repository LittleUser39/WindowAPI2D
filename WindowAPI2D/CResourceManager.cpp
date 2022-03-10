#include "framework.h"
#include "CResourceManager.h"
#include "CTexture.h"
#include "CSound.h"
CResourceManager::CResourceManager()
{
	m_mapTex = {};
}

CResourceManager::~CResourceManager()	//������ ���ҽ��� ���� - map�ȿ� ���ҽ��� �־ ���ͷ� ��ü�� ã�� 
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
	//�̹� �ִ��Ÿ� �ִ����� ��ȯ
	CTexture* pTex = FindTexture(strKey);
	if (nullptr != pTex)
		return pTex;
	//�����Ÿ� �߰�

	wstring strFilePath = CPathManager::getInst()->GetContentPath();
	strFilePath += strPath;

	pTex = new CTexture();
	pTex->Load(strFilePath);
	pTex->SetKey(strKey);		//�� Ű�� �����ϱ� ������ �װ����� ����
	pTex->SetPath(strPath);		//�� ���� ��η� ����

	m_mapTex.insert(make_pair(strKey, pTex));	//�ʿ� �ΰ��� ���� �Է��Ѵ�. �ϳ��� �񱳸� ���� Ű�� , �ϳ��� ��¥ ������
	

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
	// Sound�� �ҷ����� �� �ڷᱸ���� �̹� Sound�� �ִ��� Ȯ��
	CSound* pSound = FindSound(strkey);
	if (nullptr != pSound)
	{
		return pSound;
	}

	// Sound ���� ��� Ȯ��
	wstring strFilePath = CPathManager::getInst()->GetRelativeContentPath();
	strFilePath += strRelativePath;

	// Sound ���� �� ����
	pSound = new CSound;
	pSound->Load(strFilePath);
	pSound->SetKey(strkey);
	pSound->SetPath(strRelativePath);

	m_mapSound.insert(make_pair(strkey, pSound));

	return pSound;
}
