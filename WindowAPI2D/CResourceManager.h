#pragma once

class CTexture;
class CSound;

class CResourceManager
{
	SINGLETON(CResourceManager);

private:
	map<wstring, CTexture*> m_mapTex;	//����Ž��Ʈ�� (�ڰ�����) �񱳸� ���� Ű���� ������ ���� �ؽ�Ʈ�� (�����Ͱ�)�� ������ ����  
	map<wstring, CSound*> m_mapSound;	//���� ���� �ڷᱸ��
public:
	
	CTexture* FindTexture(const wstring& strKey); //�ؽ��� ã��
	CTexture* LoadTexture(const wstring& strKey, const wstring& strPath); //�ؽ��� �ε�

	CSound* FindSound(const wstring& strkey);
	CSound* LoadSound(const wstring& strkey, const wstring& strRelativePath);

	
};

