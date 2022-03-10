#pragma once

class CGameObject;
class CAnimation;

class CAnimator
{
	friend class CGameObject;

private:
	map<wstring, CAnimation*> m_mapAni;	//애니메이션을 보관하는 맵, 이름으로 찾고 그 애니메의 주소
	CAnimation* m_pCurAni;				//현재 애니메이션
	CGameObject* m_pOwner;				//어떤 오브젝트에 속해있는가

public:
	CAnimator();
	~CAnimator();


	CGameObject* GetObj();	

	void Render(HDC hDc);
	void Update();

	void CreateAnimation(const wstring& strName, CTexture* pTex, fPoint lt, fPoint slice, fPoint step, float duration, UINT frmcount);
	CAnimation* FindAnimation(const wstring& strname);	
	void Play(const wstring& strname);			//찾아서 그것을 현재 애니메로
};

