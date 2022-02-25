#pragma once

class CTexture;

class CResourceManager
{
	SINGLETON(CResourceManager);

private:
	map<wstring, CTexture*> m_mapTex;	//����Ž��Ʈ�� (�ڰ�����) �񱳸� ���� Ű���� ������ ���� �ؽ�Ʈ�� (�����Ͱ�)�� ������ ����  

public:
	
	CTexture* FindTexture(const wstring& strKey); //�ؽ��� ã��
	CTexture* LoadTexture(const wstring& strKey, const wstring& strPath); //�ؽ��� �ε�
};

