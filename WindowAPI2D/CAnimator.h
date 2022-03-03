#pragma once

class CGameObject;
class CAnimation;

class CAnimator
{
	friend class CGameObject;

private:
	map<wstring, CAnimation*> m_mapAni;
	CAnimation* m_pCurAni;
	CGameObject* m_pOwner;

public:
	CAnimator();
	~CAnimator();


	CGameObject* GetObj();	

	void Render(HDC hDc);
	void Update();

	void CreateAnimation(const wstring& strName, CTexture* pTex, fPoint lt, fPoint slice, fPoint step, float duration, UINT frmcount);
	CAnimation* FindAnimation(const wstring& strname);
	void Play(const wstring& strname);
};

