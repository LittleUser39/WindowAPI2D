#pragma once

class CTimeManager
{
	SINGLETON(CTimeManager);


private:
	LARGE_INTEGER m_llCurCount;		//���� ī��Ʈ
	LARGE_INTEGER m_llPrevCount;	//���� ī��Ʈ
	LARGE_INTEGER m_llFrequency;	//�ʴ� ī��Ʈ Ƚ��

	unsigned int m_uiFPS;
	double m_dDT;

public:
	
	void update(); // �� ������Ʈ�� fps,dt
	void init();   // Ÿ�� �Ŵ��� �ʱ�ȭ


	unsigned int GetFPS() { return m_uiFPS; }
	double GetDT() {return m_dDT;}
};