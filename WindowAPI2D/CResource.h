#pragma once
class CResource
{
private:
	wstring m_strKey;	//���ҽ� ������ Ű��
	wstring m_strPath;	//�ܺ��� ��θ� �ҷ���

public:
	CResource();
	virtual ~CResource();

	void SetKey(const wstring& strKey); //ũ�Ⱑ ũ�⶧���� ������ �����ö�� ���۷����� �޾���
	void SetPath(const wstring& strPath);

	const wstring& GetKey();
	const wstring& GetPath();

};

