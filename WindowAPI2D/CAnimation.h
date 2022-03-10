#pragma once

class CAnimator;
class CTexture;

struct tAniFrm
{
	fPoint fptLT;				// 왼쪽 위부터
	fPoint fptSlice;			// 얼마나 잘려져있나
	fPoint fptOffset;			// 애니메이션이 어디서 시작할껀지
	float  fDuration;			// 몇초동안 보여지나
};

class CAnimation
{
	friend class CAnimator;

private:
	wstring			m_strName;			//애니메이션 이름
	CAnimator*		m_pAnimator;		//애니메이터
	CTexture*		m_pTex;				//에니메이션 이미지
	vector<tAniFrm> m_vecFrm;			//모든 프레임의 자르기 영역 및 유지시간 넣은 백터
	int				m_iCurFrm;			//현재 프레임의 index
	float			m_fAccTime;			//현재 프레임의 축적시간

public:
	CAnimation();
	~CAnimation();

	void SetName(const wstring& strName);	//이름 설정
	const wstring& GetName();				//이름 가져오기 string은 원본을 가져옴 const로
	
	void SetFrame(int frmIndex);
	tAniFrm& GetFrame(int frmIndex);

	void Update();							//지금 장면을 몇초동안 그려야하나
	void Render(HDC hDc);
	void Create(CTexture* pTex, fPoint lt, fPoint slice, fPoint step, float duration, UINT frmcount); //애니메이션 생성
};

