#include "framework.h"
#include "CResource.h"

void CResource::SetKey(const wstring& strKey)
{
	m_strKey = strKey;
}

void CResource::SetPath(const wstring& strPath)
{
	m_strPath = strPath;
}

const wstring& CResource::GetKey()
{
	return m_strKey;
}

const wstring& CResource::GetPath()
{
	return m_strPath;
}
